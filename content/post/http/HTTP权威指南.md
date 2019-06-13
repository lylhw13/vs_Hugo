---
title: "HTTP权威指南"
date: 2019-06-02T18:17:31+08:00
draft: true
---

abbreviation | original | 中文
--- | --- | ---
SMTP | Simple Mail Transfer Protocol
FTP | File Transfer Protocol
HTTPS | Hypertext Transfer Protocol Secure
MIME | Multipurpose Internet Mail Extension | 多用途因特网邮件扩展 
URI | Uniform Resource Identifier | 统一资源标示符
TCP | Transmission Control Protocol | 传输控制协议
IP | Internet Protocol | 网际协议
DNS | Domain Name Service | 域名服务

# chapter 1

web 服务器会为所有HTTP对象数据附加一个MIME类型。
MIME类型是一种文本标记，表示一种主要的对象类型和一个特定的子类型，中间由一条斜杠来分割，例如：`image/jpeg`，`text/html`

URI 有两种形式，分别称为：
- URL 统一资源定位符，是资源的地址，是最常见形式，现在，几乎所有的 URI 都是 URL。
- URN 统一资源名，作为特定内容多唯一名称使用，与目前的资源所在地无关。 处于实验阶段，未大范围使用

