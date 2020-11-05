---
title: "C++_lock"
date: 2020-09-22T15:51:11+08:00
draft: true
---

try_to_lock
adopt_lock
defer_lock

unique_lock


- unique_lock 可以加锁，解锁。wait() 需要使用 unique_lock().
- lock_guard 只在构建时加锁，析构时解锁。不提供解锁和重新加锁的操作。

# spin lock
```c++
class spinlock_mutex{
    std::atomic_flag flag;
public:
    spinlock_mutex(): flag(ATOMIC_FLAG_INIT) {}
    
    void lock()
    {
        while(flag.test_and_set(std::memory_order_acquire));
    }
    void unlock(){
        flag.clear(std::memory_order_release);
    }
};
```