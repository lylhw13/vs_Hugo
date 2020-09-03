---
title: "Compiler"
date: 2020-09-03T15:36:50+08:00
draft: true
---

# chapter 1
compiler 编译器，输出可执行程序，属于离线方式 offline
interpreter 解释器，输出计算结果，属于在线方式 online

词法分析 -> 记号
语法分析 -> 抽象语法树
语义分析 
代码生成

AST 抽象语法树

后续遍历

栈式计算机 stack JVM


# chapter 2

字符流 -> 词法分析器 -> 记号流


正则表达式：
- 对给定的字符集 Σ = {c1, c2, ..., cn}
- 归纳定义：
  - 空串 ε 是正则表达式
  - 对于任意 c ∈ Σ，c是正则表达式
  - 如果 M 和 N 是正则表达式, 则以下也是正则表达式
    - 选择  M | N = {M, N}
    - 连接  MN = {mn| m∈M, n∈N}
    - 闭包  M* = {ε, M, MM, MMM, ...}（又叫做 Kleen 闭包）

语法糖，来简化构造：
- [c1-cn] == c1|c2|...|cn
- e+ == 一个或多个e
- e? == 零个或一个e
- "a*" == a* 自身，不是a的Kleen闭包
- e{i,j} == i到j个e的连接
- . == 除 '\n' 外的任意字符

语法糖不是必须，可以通过基本构造得到

仅仅两个操作就够：赋值和跳转



输入字符串 -> FA -> {Yes, No}

M = {Σ, S, q0, F, δ}

- Σ 字母表
- S 状态集
- q0 初始状态
- F 终结状态集
- δ 转移函数

有限状态自动机 FA

确定有限状态自动机 DFA ：
- 对于任意的字符，最多有一个状态可以转移
  - δ: S x Σ -> S

非确定状态自动机 NFA：
- 对于任意的字符，有多于一个状态可以转移
  - δ: S x (Σ U ε) -> P(S)  

幂集 P(S)

