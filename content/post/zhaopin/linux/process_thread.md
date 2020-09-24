---
title: "Process_thread"
date: 2020-09-24T23:21:33+08:00
draft: true
---

线程正常返回时不会执行清理函数。而线程在执行过程中遭到取消，才需要执行清理动作。

线程可以释放其他线程开辟的内存。比如，在生产者/消费者模型中，需要生产者线程分配内存，并把指针给消费之线程，然后由消费者线程进行释放。

It's not wrong for a thread to pass control of memory it has allocated to another thread. For example, in a producer/consumer model, it would be very reasonable for the producer thread to allocate memory for whatever it is that it produces, and then hand control over that memory to the consumer thread for the consumer thread to use and release.