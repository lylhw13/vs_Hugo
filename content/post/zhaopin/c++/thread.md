---
title: "Thread"
date: 2020-10-26T11:07:52+08:00
draft: true
---

> std::this_thread::sleep_for()

will make your thread sleep for a given time (the thread is stopped for a given time). (http://en.cppreference.com/w/cpp/thread/sleep_for)

> std::this_thread::yield()

will stop the execution of the current thread and give priority to other process/threads (if there are other process/threads waiting in the queue). The execution of the thread is not stopped. (it just release the CPU). (http://en.cppreference.com/w/cpp/thread/yield)

process 可以看作是资源的集合，比如地址空间，寄存器
thread 可以并行运算
coroutines 

线程安全和可重入不是一个概念：
- 线程安全不一定可重入， 如 malloc
- 可重入不一定线程安全

不可重入函数一般具有以下特点：
1. 已知使用静态的数据结构
2. 使用malloc 或 free
3. 是标准I/O函数

线程是操作系统的特性，而不是 C 语言的特性