---
title: "Objdump"
date: 2020-09-21T23:06:47+08:00
draft: true
---

# 通过 objdump 得到的 .text 的大小和size 得到的大小不一致。

objdump得到的是纯 .text 的值

而size 默认得到的 .text = .text + .rodata + .en_frame  

想要得到具体的值，可以使用
`size -A simplesection.o`

# 反汇编
objdump 默认输出是 AT&T 的语法格式

```sh
objdump -d test.o           // 默认输出 AT&T 格式
objdump -M intel -d test.o  // 输出 intel 的语法格式
```
