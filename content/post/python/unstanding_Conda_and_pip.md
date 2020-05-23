---
title: "Unstanding_Conda_and_pip"
date: 2020-05-14T16:11:28+08:00
draft: true
---

# 表格比较
|  |conda  | pip|
|--|--|--|
|  种类 | 二进制文件  | wheel 文件或源码 |
|是否需要编译器|否|是|
|包类型|任何|只支持python|
|创建环境|是|否，需要依赖virtualenv 或者env|
|检查依赖|是|否|
|包来源|Anaconda repo and cloud|Python Package Index (PyPI)|
|含有的Python包数量|小|大|
|安装方法| 独立安装| 随python解释器安装 |

# 补充解释
- Pip 是Python官方推荐的包管理器，随python解释器一起安装。Pip支持安装wheel文件及源代码。如果从源代码安装，需要解释器或库的支持。
- conda 目标是一个跨平台的通用包管理器，不仅局限于python。conda 独立安装，因此可以使用conda 安装python解释器。
- conda 可以创建隔离的工作环境，相当于pip和virtualenv。
- conda 可以检查处理库依赖的情况。
- Pypi 拥有的python库数量远大于 Anaconda repository。


更详细参考:
- [Understanding Conda and Pip](https://www.anaconda.com/blog/understanding-conda-and-pip)
- [What is the difference between pip and conda?](https://stackoverflow.com/a/20994790/4973450)