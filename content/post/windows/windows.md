---
title: "Windows的操作总结"
date: 2018-07-03T14:36:08+08:00
draft: false
tags: ["Windows"]
categories: ["Windows"]
---

## 添加软件的自动启动

将某软件设置为开机自启动，只需要将该脚本生成一个“快捷方式”，然后将此快捷方式放置到程序自启动文件夹之下即可,一般路径为：

`C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp`

## 添加软件链接到 Search Box

将软件的lnk文件拷贝到下面路径即可。
`C:\ProgramData\Microsoft\Windows\Start Menu\Programs`

## Windows双屏下鼠标移动的问题

当双屏设置如图所示时，鼠标只能从`screen1`的`右边`移到`screen2`上:

![multi_display_left1_right2](/media/pic/windows/multi_displays_1_2.png)

当双屏设置如图所示时，鼠标只能从`screen1`的`左边`移到`screen2`上:

![multi_display_left2_right1](/media/pic/windows/multi_displays_2_1.png)

通过拖拽调整两块屏幕的相对位置，即可以调整鼠标的穿屏方式。

## Windows的系统搜索框空白，不能返回任何结果

Windows莫名其妙的出现了空白的系统搜索框：

![Blank Search Bar](/media/pic/windows/blank_search_bar.png)

解决办法：
打开任务管理器重启`SearchUI.exe`线程。

## 被其他线程占用的文件的删除办法

从这个页面[Handle v4.11](https://docs.microsoft.com/zh-cn/sysinternals/downloads/handle)下载handle。
然后解压到某一路径下，比如`D:/Handel/handle64.exe`

```sh
C:\>C:\Handle\handle64.exe filename -a  #显示出所有占用该文件的线程
taskkill /pid pidnumber /f  #将pidnumber替换为你查到的线程号
rmdir dirname /s/q  #静默循环删除相关文件及文件夹
```