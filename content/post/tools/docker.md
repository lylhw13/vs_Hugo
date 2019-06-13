---
title: "Docker"
date: 2019-06-02T16:31:00+08:00
draft: true
---

# [Docker 入门教程](http://www.ruanyifeng.com/blog/2018/02/docker-tutorial.html)

RUN命令与CMD命令的区别在哪里？简单说，RUN命令在 image 文件的构建阶段执行，执行结果都会打包进入 image 文件；CMD命令则是在容器启动后执行。另外，一个 Dockerfile 可以包含多个RUN命令，但是只能有一个CMD命令。