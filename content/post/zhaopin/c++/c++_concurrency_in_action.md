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