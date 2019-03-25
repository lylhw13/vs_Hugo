---
title: "Static_const"
date: 2019-03-22T15:56:11+08:00
draft: true
---

# [static const vs. const, when to use each](http://www.cplusplus.com/forum/beginner/40666/)

If the constant will be the same every time the function is called, use static const.

If the constant is only constant for the lifetime of the function and may change depending on on how/when the function is called, use const.

Usually you will want to use static const. Though in practice the compiler will likely optimize for you so it probably doesn't matter.