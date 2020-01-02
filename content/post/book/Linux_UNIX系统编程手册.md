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