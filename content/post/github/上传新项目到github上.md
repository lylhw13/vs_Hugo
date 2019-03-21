---
title: "上传新项目到github上"
date: 2018-07-31T11:12:10+08:00
draft: False
tags: ["Github"]
categories: ["Github"]
---


# 在github网页端，新建仓库，没有进行初始化
```git
# local directory
git init
git add .
git commit -m "First commit"

# set teh new romote
git remote add origin [remote repository url]

# verifies the new remote url
git remote -v

# push the chagnes
git push origin master
```

# 在github网页端，新建仓库且已经初始化
```git
git init
git pull [remote repostitory url]
git add .
git commit -m "First commit"


# set teh new romote
git remote add origin [remote repository url]

# verifies the new remote url
git remote -v

# push the chagnes
git push origin master
```
