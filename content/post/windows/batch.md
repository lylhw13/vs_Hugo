---
title: "Batch"
date: 2018-07-03T14:02:11+08:00
draft: true
tags: ["cmd", "Windows"]
categories: ["Windows"]
---

# Windows中Bacth命令总结

## 将Windows中cmd的输出结果重定向到文件里

```sh
ping archlinux.org > D:/log.txt #会覆盖之前的结果
ping archlinux.org >> D:/log.txt #在之前的基础上追加输出
```