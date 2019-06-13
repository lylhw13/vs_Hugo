---
title: "Pro_git_2"
date: 2019-06-13T17:00:07+08:00
draft: true
---

集中化的版本控制系统（Centralied Version Control Systems, 简称 CVCS）
分布式版本控制系统（Distributed Version Control System，简称 DVCS）

Git 更像是把数据看作是对小型文件系统的一组快照。Git 更像是一个小型的文件系统，提供了许多以此为基础构建的超强工具，而不只是一个简单的 VCS。 

Git 中所有数据在存储前都计算校验和，然后以校验和来引用。Git 用以计算校验和的机制叫做 SHA-1 散列（hash，哈希）。
实际上，Git 数据库中保存的信息都是以文件内容的哈希值来索引，而不是文件名。

Git 一般只添加数据

Git 有三种状态，你的文件可能处于其中之一：已提交（committed）、已修改（modified）和已暂存（staged）。 已提交表示数据已经安全的保存在本地数据库中。 已修改表示修改了文件，但还没保存到数据库中。 已暂存表示对一个已修改文件的当前版本做了标记，使之包含在下次提交的快照中。

由此引入 Git 项目的三个工作区域的概念：Git 仓库、工作目录以及暂存区域。

暂存区域是一个文件，保存了下次将提交的文件列表信息，一般在 Git 仓库目录中。

```git
git config --list           # 检查配置信息
git config user.name        # 查看某一配置

git help <verb>
git <verb> --help
man git-<verb>
```