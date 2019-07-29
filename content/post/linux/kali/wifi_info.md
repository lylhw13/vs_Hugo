---
title: "Wifi_info"
date: 2019-07-20T10:41:29+08:00
draft: true
---

Refer to [无线网络安全测试初探](https://www.anquanke.com/post/id/162209)

AP：Access Point,中文名”无线访问接入点“，在本篇文章中，无线路由器也指AP。AP的功能主要使无线设备能够快速轻易地与无线网络连接，是无线设备与有线局域网络的桥梁。

IEEE 802.11协议：说起无线网络，那么就不得不提到IEEE 802.11标准，该协议主要用于解决终端之间的无线接入，包括wifi，蓝牙等等。所以，学习无线网络的相关知识，翻阅IEEE 802.11文档是必须的。

Aircrack-ng：一个与IEEE 802.11标准的无线网络分析有关的安全软件。

SSID：Service Set Identifier ，中文名为服务集标识。在本篇中，运用Aircrack-ng的界面中，有出现BSSID和ESSID，在其中BSSID指的是AP的MAC地址，ESSID为AP的名称。

加密模式：

- WPS加密（Wi-FI Protected Setup）
    PIN码（Pin Input Configuration,个人识别码模式）
    WPS也叫作QSS
- WEP加密（Wired Equivalent Privacy,有效等效保密协议）,WEP已经逐渐  被WPA-PSK/WPA2-PSK模式取代
- WPA-PSK/WPA2-PSK加密（Wi-Fi Protected Access）

## PMKID

PMKID(the Pairwise Master Key Identifier ，成对主密钥标识符)
