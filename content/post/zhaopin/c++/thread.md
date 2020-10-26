---
title: "Thread"
date: 2020-10-26T11:07:52+08:00
draft: true
---

> std::this_thread::sleep_for()

will make your thread sleep for a given time (the thread is stopped for a given time). (http://en.cppreference.com/w/cpp/thread/sleep_for)

> std::this_thread::yield()

will stop the execution of the current thread and give priority to other process/threads (if there are other process/threads waiting in the queue). The execution of the thread is not stopped. (it just release the CPU). (http://en.cppreference.com/w/cpp/thread/yield)