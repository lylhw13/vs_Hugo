---
title: "上传新项目到github上"
date: 2018-07-31T11:12:10+08:00
draft: False
tags: ["github"]
---

# 上传新项目到github上

在本地文件夹下面的操作：

```sh
cd you_work_directory
git init
git add README.md
git commit -m "first commit"
```

在github网页端，新建一个仓库，但是不要初始化。接着执行

```sh
git remote add origin git@github.com:lylhw13/new_repository.git
git push -u origin master
```