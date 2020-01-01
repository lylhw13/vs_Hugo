---
title: "Unix_linux编程实践教程"
date: 2019-12-14T10:18:01+08:00
draft: true
---

权限
user group other

bc - An arbitrary precision calculator language.
dc - an arbitrary precision calculator. desk calculator.

bc 是dc 的预处理器，它将表达式转换成逆波兰表达式。

who -- display who is logged in
man - format and display the on-line manual pages
与普通文件不同的是，目录文件永远不为空，每个目录都至少包含"." 和 ".."

## 3
dir, dirent -- directory file format

creat建立一个普通文件，文件一经创建，类型就无法修改。
系统调用chmod不受“新建文件掩码”的影响。

## 4
link拒绝创建跨越设备的链接，rename拒绝在不同的文件系统间进行i-节点号的转移。符号链接可以跨越文件系统。

## 5
与磁盘文件的链接通常包含缓冲区，从进程到磁盘到字节先被缓冲，然后才从内核到缓冲区发送出去。磁盘链接具有缓冲这样一个属性。到终端到链接则不同，进程需要尽快把到终端到数据传送出去。
回显是链接的一个属性，到磁盘文件的链接没有这些属性。

Unix是一个时间共享系统。
自动添加模式auto-append mode
race condition竞争
原子操作
icrnl是Input: convert Carriage Return to NewLine（输入时将回车转换为换行）
onlcr是Output: add to NewLine a Carriage Return（输出时在新的一行加入回车）
一个属性前的减号表示这个操作被关闭。

驱动程序和驱动程序设置被存储在内核，而不是在进程。

## 6
大多数进程自动将前3个文件描述符打开。它们不需要调用open()来建立连接。

中断信号通常是编码2。

## 9
所有的Unix程序都遵从以0退出表明成功这一惯例。
变量都是字符串类型都，没有数值型都变量。

## 10
- shell并不将重定向标记和文件名传递给程序。
- 重定向可以出现在命令中的任何地方并且在重定向标识符周围并不需要空格来区分。重定向符号并不能终止命令和参数，它不过是一个附加的请求而已。

最低可用文件描述符 Lowest Avaialble fd
当打开文件时，为此文件安排的描述符总是此数组中最低可用位置的索引。
文件描述符集合通过exec调用传递，且不会改变。
shell使用进程通过fork产生子进程与子进程调用exec之间的时间间隔来重定向标准输入输出到文件。

## 11
协同进程 coroutines