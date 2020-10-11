---
title: "图解TCP_IP"
date: 2020-10-11T19:10:03+08:00
draft: true
---

ISO: International Organization for Standards
OSI: Open Systems Interconnection
MAC: Media Access Control 介质访问控制

上下层之间进行交互时所遵循的约定叫做“接口”。同一层之间的交互所遵循的约定叫做“协议”。

根据接收端数量分类：
- 单播 Unicast
- 广播 Broadcast
- 多播 Multicast 指定多个接受对象
- 任播 Anycast 实际应用中有DNS根域名解析服务器

MAC 地址和IP 地址都具有唯一性，但是只有IP 地址有层次性


- 网卡
    使计算机连网的设备 Network Interface
- 中继器 Repeater
    处于OSI 模型的第一层，从物理层上延长网络的设备。中继器只单纯转发，不判断数据是否有错误，不能在传输速度不同的媒介之间转发。
- 网桥 Bridge / 2层交换机
    处于OSI 模型的第二层，从数据链路层上延长网络的设备。网桥根据 MAC 地址进行处理
- 路由器 Router / 3层交换机
    通过网络层转发分组数据的设备。路由器根据 IP 地址进行处理。
- 4-7 层交换机
    处理传输层以上各层网络传输的设备
- 网关 Gateway
    转换协议的设备，是 OSI 参考模型中负责将从传输层到应用层的数据进行转换和转发的设备。它与 4-7 层交换机一样都是处理传输层及以上的数据，但是网关不仅转发数据还负责对数据进行转换。

网络分为三层：
- 接入网，接入层
- 承载网，边缘网络，汇聚层
- 核心网，骨干层