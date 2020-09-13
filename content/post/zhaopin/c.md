---
title: "C"
date: 2020-09-13T17:00:18+08:00
draft: true
---

new/delete
1. 返回一个有类型的指针
2. new 不会返回NULL，失败时会抛出一个异常
3. 会调用构造函数和析构函数
4. 调用是通过指定类型（编译器计算大小）
5. 是否调用 malloc/free 是基于实现的

malloc/free
1. 返回 void*
2. 失败时返回 NULL
3. 调用时通过指定大小 (in bytes)