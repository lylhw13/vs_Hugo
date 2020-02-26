---
title: "APUE"
date: 2020-01-11T18:26:20+08:00
draft: true
---

restrict keyword in C
In the C programming language (after 99 standard), a new keyword is introduced known as restrict.

- restrict keyword is mainly used in pointer declarations as a type qualifier for pointers.
- It doesn’t add any new functionality. It is only a way for programmer to inform about an optimizations that compiler can make.
- When we use restrict with a pointer ptr, it tells the compiler that ptr is the only way to access the object pointed by it and compiler doesn’t need to add any additional checks.
- If a programmer uses restrict keyword and violate the above condition, result is undefined behavior.
- restrict is not supported by C++. It is a C only keyword.

# chapter 4
umask 是少数几个没有出错返回函数中的一个。