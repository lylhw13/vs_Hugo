---
title: "The_rule_of_five"
date: 2020-09-26T22:09:59+08:00
draft: true
---

Safely and efficiently implement RAII to encapsulate the management of dynamically allocated resources.
安全高效的封装对动态内存的管理，以实现RAII

# the ruler of three:
If you define or =delete any copy, move, or destructor function, define or =delete them all.
一个类如果实现类以下任意一个函数，就必须将以下三个函数全部实现
- copy constructor
- copy assignment operator
- destructor

这些函数一般用在需要管理动态内存的类中，所以以上三个必须都要实现。

# the ruler of five:
是对于上面法则的扩充，上面函数的实现，会组织编译器自动生成以下函数，为了实现对拷贝的优化，则需要实现以下函数：
- move constructor
- move assignment operator

```c++

```