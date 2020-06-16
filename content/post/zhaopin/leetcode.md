---
title: "Leetcode"
date: 2020-06-13T23:13:17+08:00
draft: true
---

典型写法

消除低位的1
k = k ^ (k - 1);

k & -k; //取最后一位的1