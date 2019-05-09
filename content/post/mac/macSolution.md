---
title: "MacSolution"
date: 2019-05-07T19:15:11+08:00
draft: true
---

# some solution for mac problems

## Mac 下 Zip 压缩包解压后文件名出现乱码，怎么解决？
Mac OS 下，Zip 格式的压缩包解压之后出现乱码，是因为别人压缩制作这个 Zip 压缩包的时候，用的是非UTF-8编码（如Windows中文版的默认字符编码为 GB2312），而 Mac 自带的 归档实用工具 解压 Zip 格式文件的时候使用的字符编码是 Mac OS 默认的字符编码（UTF-8），所以导致解压后的文件名出现乱码。

使用解压软件 `The Unarchiver` 来解压 Zip 格式的文件。
refer to <http://biang.io/blog/development/tools/os/osx/other/Mac-Zip-package-after-decompression-file-name-appear-garbled-how-to-solve>
