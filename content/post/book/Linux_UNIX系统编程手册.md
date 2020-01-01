---
title: "Linux_UNIX系统编程手册"
date: 2020-01-01T21:52:15+08:00
draft: true
---

# chapter 3
#include <unistd.h> /*Prototypes for many system calls*/

# chapter 4
fd file descriptor

O_RDWR 并不等同于O_RDONLY|O_WRONLY，后者（或组合）属于逻辑错误。

系统调用不会分配内存缓冲区用以返回信息给调用者。所以，必须预先分配大小合适的缓冲区并将缓冲区指针传给系统调用。与此相反，有些库函数却会分配内存缓冲区用以返回信息给调用者。