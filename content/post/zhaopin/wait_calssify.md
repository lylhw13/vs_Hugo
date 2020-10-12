---
title: "Wait_calssify"
date: 2020-08-23T10:07:56+08:00
draft: true
---


# 调页算法有哪些呢？
lru，lfu，fifo，理想化的opt。

# 滑动窗口知道吧，讲讲滑动窗口？拥塞控制的四个算法知道吧，讲讲四个算法？

# DDoS 攻击，如何防御
# 客户端如何保存登录状态
# 跨域登录状态保持，从 taobao.com 切换到 tmall.com

MySQL 数据库怎么做高可用

C++ private继承下的protect函数具体会怎么样

银行家算法了解吗

socket 分类
Socket有三类。
第一种是SOCK_STREAM(流式)，提供面向连接的可靠的通信服务，比如telnet,http。
第二种是 SOCK_DGRAM(数据报)，提供无连接不可靠的通信，比如UDP。
第三种是SOCK_RAW(原始)，主要用于协议的开发和测试，支持通信底层操 作，比如对IP和ICMP的直接访问。


霍夫曼树

用的什么协议来读取网络摄像头的？（rstp。）rstp是基于什么协议的？
RSTP（rapid spanning Tree Protocol ），即快速生成树协议

IPML
一个基本的材料库，头文件改动以后，引发连锁反应

具有扎实的C/C++编程能力，具有良好的编程风格，能对立、优质、高效完成功能模块
具有良好的学习能力和分析解决问题的能力，具有良好的团队协作能力

友元类 友元函数

如果服务器接受连接时负载过大，如何进行流量控制？
如果检测网络中出现拥塞？
如何设计可靠的RUDP传输？
class的内存模型。


课题名称：具有器件级、工艺级、系统级设计功能的微纳传感器综合设计工具开发
执行期限：2019年07月至2022年6月
人员分类：课题骨干

公司曾多次承担国家、省、市级项目。

微纳传感器与电路协同设计技术及设计工具研发
非线性
解微分方程
多项式拟合

流固耦合

有一部分引擎是自研的

能够阅读英文技术书籍

工作遇到的最难的问题

自我介绍
My name is liu. 
I graduated from xianjiaotong university with a master degree in 2016. 
I have over four years of experience in program developing. My main job is to develop and maintain the MEMS CAE software. 
I am experienced C/C++ and familiar with linux and tcp/ip protocol.

For me, my biggest advantage is cooperationg with others and I think I'm a good team player and I'm a person of great honesty to ohters. Also I am able to work under great pressure. I hope you can give me the chance.

工作内容
My main job is to develop and maintain the MEMS CAE software suit. The software is used to do mulit-physics analysis. The software by solving physics equations, like Newton's Law, to simulate the deformation of the object which at some situation, for example force, electric and so on. The software can reduce the time and money for the progress. Half of my work is to solve funciton of physics and the left time is to develop.

the main market for our products is japan and us.

so our email and document is written in english.

power engineering

- why are you interested in our company?
    First of all, thank you for this interview opportunity. I am so honored to be here.

    Your company has an impressive reputation.

- Why are you qualified for this job?
- What makes you a good fit for the company?

Strengths:
- I like to take initiative. 主动性很强
- I like being proactive. 主动性很强
- I am self-motivated.

- I am open and willing to learn.
- I am hard working.

- I am a strong team player.
- I am very team-oriented.

- I am trustworthy
- I am reliable
- I have a strong sense of responsibility


Weaknesses:

- Why do you move around so much?
I wanted to acquire as much knowledge as possible.

- Do you have any question for us?
Can you tell me what kind of projects that I will be involved if I got an offer on this job?
Will there be any in-hours training from the company?


工作中，通过物理分析，求解数学方程，使用python进行快速原型，最后C/C++代码落地。


三维曲面的拟合，使用的是多项式拟合曲面，最小二乘法，使用矩阵求逆，但是遇到某些矩阵的结果值不正确，就注意到有些矩阵不存在逆矩阵，这时候应该求伪逆，就是先乘上一个转置矩阵，再进行求逆。
同时支持二维多项式拟合。
比如矩阵求逆，直接利用矩阵的定义，即伴随矩阵法进行求解，当时对于稍微大一点的矩阵，速度明显不行。最后改为LU矩阵分解。

非线性问题：
非线性降阶宏模型的抽取仿真，控制方程是一个高阶微分方程，这样的方程没有解析解，一般的物理分析为了简化运算，会舍弃这个高阶项，把方程转化为线性方程，但是这样的求解会让模型失真，比如这种解法在小范围变形的时候，可以很好的符合物理结果，但是对于大范围变形，因为高阶项的舍去，就会造成很大的误差。目前这一块都没有很好的解法。
通过大量阅读文献，总结出一中比直接舍弃最高项更优的解法，就是在一定的物理条件假设下，将这个高阶微分方程转换为一个没有微分项的高阶多次方程，这个方程最高项为6次，因为根据证明一般的五次方程不存在根式解，

涉及的矩阵均为非稀疏矩阵，给高效求解带来困难；需要用特殊方法（CHIEF法等）来处理计算过程中出现的奇异性和数值不稳定性问题

有限元的核心一是求PDE(偏微分方程)的近似解，二是离散化(discretization)。
PDE(偏微分方程)
离散化(discretization): 一个连续的介质会被离散成数个简单的基本几何单元,即element。这些elements是通过节点(nodes)相互联系。这个过程就是通常所说的网格划分(mesh)。

培养了严谨，经常要大量分析数据，不能有一丝一毫的差别
经过工程化的培养
