#include <mutex>
#include <queue>
#include <condition_variable>

template <typename T>
class threadsafe_queue {
private:
    mutable std::mutex mtx;
    std::queue<T> data_queue;
    std::condition_variable cv;

public:
    threadsafe_queue() {}

    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mtx);
        data_queue.push(move(new_value));
        cv.notify_one();
    }

    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lk(mtx);
        if (data_queue.empty())
            return false;

        value = move(data_queue.front());
        data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop() {
        std::lock_guard<std::mutex> lk(mtx);
        if (data_queue.empty())
            return std::make_shared<T>();

        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mtx);

        cv.wait(lk, [this] {return !data_queue.empty(); });
        value = move(data_queue.front());
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mtx);

        cv.wait(lk, [this] {return !data_queue.empty();});

        std::shared_ptr<T> res(std::make_shared<T>(move(data_queue.front())));
        data_queue.pop();
        return res;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lk(mtx);
        return data_queue.empty();
    }

};

