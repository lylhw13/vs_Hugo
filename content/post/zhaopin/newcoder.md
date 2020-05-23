---
title: "Newcoder"
date: 2020-05-21T14:10:46+08:00
draft: true
---

HTTP会话的四个过程
1. 建立tcp连接
2. 发出请求文档
3. 发出响应文档
4. 释放tcp连接

类的继承后方法属性变化：

private 属性不能够被继承。

使用private继承，父类的protected和public属性在子类中变为private；

使用protected继承，父类的protected和public属性在子类中变为protected；

使用public继承，父类中的protected和public属性不发生改变; 

private, public, protected 访问标号的访问范围：

private：只能由1.该类中的函数、2.其友元函数访问。
不能被任何其他访问，该类的对象也不能访问。

protected：可以被1.该类中的函数、2.子类的函数、以及3.其友元函数访问。
但不能被该类的对象访问。

public：可以被1.该类中的函数、2.子类的函数、3.其友元函数访问，也可以由4.该类的对象访问。
 
注：友元函数包括3种：设为友元的普通的非成员函数；设为友元的其他类的成员函数；设为友元类中的所有成员函数。

第一设计范式:  所有属性不可以再划分，用于保证列的原子性