---
title: "Linux_UNIX系统编程手册"
date: 2020-01-01T21:52:15+08:00
draft: true
---

# chapter 2
UNIX 系统没有文件结束符的概念，读取文件时如无数据返回，便会认定抵达文件末尾。

# chapter 3
#include <unistd.h> /*Prototypes for many system calls*/

# chapter 4
fd file descriptor

O_RDWR 并不等同于O_RDONLY|O_WRONLY，后者（或组合）属于逻辑错误。

系统调用不会分配内存缓冲区用以返回信息给调用者。所以，必须预先分配大小合适的缓冲区并将缓冲区指针传给系统调用。与此相反，有些库函数却会分配内存缓冲区用以返回信息给调用者。

# chapter 5
原子性是readv() 和 write() 的重要属性。

# chapter 6
argc / argv 参数机制的局限之一在于这些变量仅对main() 函数可用。 p100

# chapter 7
malloc() 返回内存块所采用的字节对齐方式，总是适宜于高效访问任何类型的C语言数据结构。
free() 释放同一块已分配内存超过一次是错误的。
若非经由malloc函数包中函数所返回的指针，绝不能在调用free()函数时使用。

# chapter 15

符号链接自创建起，其所有权限便为所有用户共享，且这些权限也不得更改。对符号链接进行解引用时，将忽略所有这些权限。p251

# chapter 18
ls -F 命令的输出结果中会在符号链接的尾部标记@。

文件的链接计数中并未将符号链接计算在内。


# chapter 20

c语言不会对自动变量进行初始化。 p337

# chapter 24
copy-on-write
除非速度绝对重要的场合，新程序应当舍vfork()而取fork()。原因在于，当使用写时复制语义实现fork()（大部分现在UNIX实现皆是如此）时，在速度几近于vfork()的同时，又又避免了vfork()的怪异行为。


# chapter 26
在shell中，可通过读取 $? 变量值来获取上次执行命令对终止状态。

# chapter 27
argv 是由字符串指针所组成的列表，以NULL结束。
由于是将调用程序取而代之，对execve()的成功调用将永不返回，而且也无需检查execve() 的返回值，因为该值总是等于-1。实际上，一旦函数返回，就表明发生来错误。

将某一shell命令实现为内建命令，不外乎两个目的：效率以及对shell产生副作用(side effect)。

实际上FD_CLOEXEC是文件描述符标志中唯一可以操作的一位。该位对应值为1。p476
当使用dup(), dup2() 或 fcntl()为一文件描述符创建副本时，总是会清楚副本描述符的执行时关闭标志。

# chapter 30
mutex是mutual exclusion的缩写。

互斥量的实现采用来机器语言级的原子操作（在内存中执行，对所有线程可见），只有发生锁对争用时才会执行系统调用。

# chapter 44
管道只能用于相关进程之间的通信。p733

命名管道FIFO，可以用于非相关进程之间的通信。

# chapter 56

AF address family 地址族
PF protocol family 协议族

In the Internet domain, datagram sockets employ the User Datagram Protocol (UDP), and stream sockets (usualy) employ the Transmission Control Protocol (TCP). p1152

# chapter 58

maximum transmission unit (MTU) 最大传输单元
