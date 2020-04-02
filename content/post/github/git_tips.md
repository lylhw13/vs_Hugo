---
title: "git tips"
date: 2018-07-01T11:57:30+08:00
draft: false
tags: ["GitHub"]
categories: ["Summary"]
---

# git tips

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
git checkout target-branch-id          # check out to the target branch
```

## git clone a specific branch

```sh
    git clone -b <branch> <remote_repo>
```

Example:
```sh
    git clone -b my-branch git@github.com:user/myproject.git
```

With Git 1.7.10 and later, add --single-branch to prevent fetching of all branches. Example, with OpenCV 2.4 branch:
```sh
    git clone -b opencv-2.4 --single-branch https://github.com/Itseez/opencv.git
```
refer to <https://stackoverflow.com/questions/1911109/how-to-clone-a-specific-git-branch>

## git clone including submodules

With version 2.13 of Git and later use --recurse-submodules
```git
git clone --recurse-submodules https://github.com/spyder-ide/spyder.git -j8
```
Tips: -j8 is an optional performance optimization that became available in version 2.8, and fetches up to 8 submodules at a time in parallel — see man git-clone.

## Throw away local commits in Git
refer to <https://stackoverflow.com/questions/5097456/throw-away-local-commits-in-git>

Delete the most recent commit:
```git
git reset --hard HEAD~1
```
Delete the most recent commit, without destroying the work you've done:
```git
git reset --soft HEAD~1
```

## Override local files
```git
git fetch --all
git reset --hard <remote>/<branch_name>
```
For example
```git
git fecth -all
git reset --hard origin/master
```

# Problems

## Asking for entering passphrase for C:\User\TEM/.ssh/id_rsa every time.

```sh
ssh-add
```

refer to 
- <https://github.com/cmderdev/cmder/issues/1781>
- <https://stackoverflow.com/questions/21095054/ssh-key-still-asking-for-password-and-passphrase>

