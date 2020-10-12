---
title: "C++_concurrency_in_action"
date: 2020-09-22T09:06:33+08:00
draft: true
---

```sh
g++ -std=c++11 -pthread hello_world.cpp

# 如果不加 -pthread,  会出现 undefined reference to `pthread_create' 错误
```


# chapter 1
concurrency is about two or more separate activities happening at the same time.

the only reason not to use concurrency is when the benefit is not worth the cost.

every thread has to have an initial function, which is where the new thread of execution begins.

# chapter 2
std::thread works with any callable type, so you can pass an instance of a class with a function call operator to the std::thread constructor instead

a function object
```c++
class background_task
{
public:
    void operator()() const
    {
    do_something();
    do_something_else();
    }
};
background_task f;
std::thread my_thread(f);
```

The act of calling join() also cleans up any storage associated with the thread, so the std::thread object is no longer associated with the now-finished thread; it isn’t associated with any thread. This means that you can call join() only once for a given thread; once you’ve called join() , the std::thread object is no longer joinable, and joinable() will return false 

Resource Acquisition Is Initialization ( RAII )

Using RAII to wait for a thread to complete
```c++
class scoped_guard{
    std::thread t;
public:
    explicit thread_guard(std::thread t_): t(std::move(t_)) {}

    ~thread_guard(){
        if(t.joinable())
            t.join();
    }

    thread_guard(const thread_guard&)=delete;
    thread_guard& operator=(const thread_guard&)=delete;
};
```

But it’s important to bear in mind that by default the arguments are copied into internal storage, where they can be accessed by the newly created thread of execution, even if the corresponding parameter in the function is expecting a reference.

默认情况下，参数是复制到新线程，不管是不是引用传递

thread objects cannot be copied

std::ifstream, std::unique_ptr are movable but not copyable
```c++
std::thread::hardware_concurrency() //returns the number of concurrent threads supported by the implementation
```

software transactional memory ( STM ),

synchronization primitive called a mutex (mutual exclusion)

the Standard C++ Library provides the std::lock_guard class template, which implements that
RAII idiom for a mutex; it locks the supplied mutex on construction and unlocks it on destruction, thus ensuring a locked mutex is always correctly unlocked. 

Don’t pass pointers and references to protected data outside the scope of the lock, whether by
returning them from a function, storing them in externally visible memory, or passing them as
arguments to user-supplied functions.


```c++
template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};
template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const length = std::distance(first, last);
	if (!length)
		return init;
	unsigned long const min_per_thread = 25;
	unsigned long const max_threads =
		(length + min_per_thread - 1) / min_per_thread;
	unsigned long const hardware_threads =
		std::thread::hardware_concurrency();
	unsigned long const num_threads =
		std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
	unsigned long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);	// 少申请一个线程，因为当前线程已经占据一个，用当前线程处理剩余的边界量

	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(
			accumulate_block<Iterator, T>(),
			block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}
	accumulate_block()(block_start, last, results[num_threads - 1]);
	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));
	return std::accumulate(results.begin(), results.end(), init);
}

#include <atomic>
#include <functional>
#include <thread>
#include <condition_variable>

template<typename T>
class thread_safe_queue
{
private:
	mutable std::mutex mut;
	std::queue<T> data_queue;
	std::condition_variable data_cond;
public:
	thread_safe_queue()
	{}
	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(std::move(data));
		data_cond.notify_one();
	}
	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		value = std::move(data_queue.front());
		data_queue.pop();
	}
	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		std::shared_ptr<T> res(
			std::make_shared<T>(std::move(data_queue.front())));
		data_queue.pop();
		return res;
	}
	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return false;
		value = std::move(data_queue.front());
		data_queue.pop();
		return true;
	}
	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res(
			std::make_shared<T>(std::move(data_queue.front())));
		data_queue.pop();
		return res;
	}
	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};

class join_threads
{
	std::vector<std::thread>& threads;
public:
	explicit join_threads(std::vector<std::thread>& threads_) :
		threads(threads_)
	{}
	~join_threads()
	{
		for (unsigned long i = 0; i < threads.size(); ++i)
		{
			if (threads[i].joinable())
				threads[i].join();
		}
	}
};

class thread_pool
{
	std::atomic_bool done;
	thread_safe_queue<std::function<void()> > work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;
	void worker_thread()
	{
		while (!done)
		{
			std::function<void()> task;
			if (work_queue.try_pop(task))
			{
				task();
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}
public:
	thread_pool() :
		done(false), joiner(threads)
	{
		unsigned const thread_count = std::thread::hardware_concurrency();
		try
		{
			for (unsigned i = 0; i < thread_count; ++i)
			{
				threads.push_back(
					std::thread(&thread_pool::worker_thread, this));
			}
		}
		catch (...)
		{
			done = true;
			throw;
		}
	}
	~thread_pool()
	{
		done = true;
	}
	template<typename FunctionType>
	void submit(FunctionType f)
	{
		work_queue.push(std::function<void()>(f));
	}
};

```