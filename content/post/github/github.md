---
title: "GitHub 问题汇总"
date: 2018-07-01T11:57:30+08:00
draft: true
tags: ["GitHub"]
categories: ["Summary"]
---

# GitHub 问题汇总

## Error 1

使用git push时出现error: src refspec master does not match any.

参考链接<https://segmentfault.com/q/1010000004615080>

```sh
error: src refspec master does not match any.
error: failed to push some refs to "xxxxxxx"
```

### 解决办法

一般这种情况是因为push的时候暂存区没有文件，所以无法push。

## Error 2

使用git push时出现`error: failed to push some refs to 'git@github.com:***/***.git'`

参考链接<https://www.cnblogs.com/daemon369/p/3204646.html>

参考链接<https://stackoverflow.com/questions/10298291/cannot-push-to-github-keeps-saying-need-merge>

这种错误是远程repository和我本地的repository版本冲突导致的。
产生这种问题是因为分别在远程的repository和本地的repository执行`git init`，这样在执行`git push`的时候就会产生这样版本冲突的问题。

### 解决办法

如果远程repository不重要，就强制push:

```git
git push -f origin master
```

# git commands

## Windows下无法手动创建 `.gitignore`文件

在Windows下面试图通过创建一个文本文件，然后更改名称为`.gitignore`的时候，系统会提醒说:`You must type a file name.`。造成无法创建类似名称的文件。

### 解决办法

采用命令行生成这样一个文件。

```sh
touch .gitignore
```

## git checkout 到指定版本

```sh
git log         # show commit logs
git checkout branch-id          # check out to the target branch
```