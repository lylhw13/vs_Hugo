---
title: "Asio"
date: 2020-11-24T09:26:22+08:00
draft: true
---

在程序中你需要创建至少一个io_context实例。

date: 2020-11-23T23:27:49+08:00
draft: true
---

The asio library provides a guarantee that callback handlers will only be called from threads that are currently calling io_context::run(). Therefore unless the io_context::run() function is called the callback for the asynchronous wait completion will never be invoked.

The io_context::run() function will also continue to run while there is still "work" to do. In this example, the work is the asynchronous wait on the timer, so the call will not return until the timer has expired and the callback has completed.

It is important to remember to give the io_context some work to do before calling io_context::run(). For example, if we had omitted the above call to steady_timer::async_wait(), the io_context would not have had any work to do, and consequently io_context::run() would have returned immediately.
It is important to remember to give the io_context some work to do before calling io_context::run(). For example, if we had omitted the above call to steady_timer::async_wait(), the io_context would not have had any work to do, and consequently io_context::run() would have returned immediately.

A resolver takes a host name and service name and turns them into a list of endpoints.

Note that we are using boost::asio::async_write(), rather than ip::tcp::socket::async_write_some(), to ensure that the entire block of data is sent.

Data may be read from or written to a connected TCP socket using the receive(), async_receive(), send() or async_send() member functions. However, as these could result in short writes or reads, an application will typically use the following operations instead: read(), async_read(), write() and async_write().

TCP clients may establish connections using the free functions connect() and async_connect(). These operations try each endpoint in a list until the socket is successfully connected. 

Data may be read from or written to an unconnected UDP socket using the receive_from(), async_receive_from(), send_to() or async_send_to() member functions. For a connected UDP socket, use the receive(), async_receive(), send() or async_send() member functions.

Your program will have at least one I/O execution context, such as an boost::asio::io_context object, boost::asio::thread_pool object, or boost::asio::system_context. This I/O execution context represents your program's link to the operating system's I/O services.

your_completion_handler is a function or function object with the signature:
```c++
void your_completion_handler(const boost::system::error_code& ec);  // must be const
```
