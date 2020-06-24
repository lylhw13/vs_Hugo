---
title: "C++"
date: 2020-06-18T22:52:49+08:00
draft: true
---

1. C++面向对象的三种特性？（每条详细说说）
   面向对象的三个基本特征是：封装、继承、多态。
   封装，也就是把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。
   面向对象编程 (OOP) 语言的一个主要功能就是“继承”。继承是指这样一种能力：它可以使用现有类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。
   多态性（polymorphisn）是允许你将父对象设置成为和一个或更多的他的子对象相等的技术，赋值之后，父对象就可以根据当前赋值给它的子对象的特性以不同的方式运作。简单的说，就是一句话：允许将子类类型的指针赋值给父类类型的指针。

    实现多态，有二种方式，覆盖，重载。

    覆盖，是指子类重新定义父类的虚函数的做法。

    重载，是指允许存在多个同名函数，而这些函数的参数表不同（或许参数个数不同，或许参数类型不同，或许两者都不同）。

    其实在《Thinking in java》里有提到，当你用继承的时候，肯定是需要利用多态的特性。如果用不到多态的特性，继承的关系是无用的。

    多用组合，少用继承。

Q: 为何成员函数不是默认为虚？
A: 因为许多类不是被用来做基类的。 例如，复数类就是如此。
另外，有虚函数的类有虚机制的开销[译注：指存放vtable带来的空间开销和通过vtable中的指针间接调用带来的时间开销]，通常而言每个对象增加的空间开销是一个字长。这个开销可不小，而且会造成和其他语言（比如C，Fortran）的不兼容性——有虚函数的类的内存数据布局和普通的类是很不一样的。[译注：这种内存数据布局的兼容性问题会给多语言混合编程带来麻烦。]

Because many classes are not designed to be used as base classes. For example, see class complex.
Also, objects of a class with a virtual function require space needed by the virtual function call mechanism - typically one word per object. This overhead can be significant, and can get in the way of layout compatibility with data from other languages (e.g. C and Fortran).

1. Why are destructors not virtual by default?
Because many classes are not designed to be used as base classes. Virtual functions make sense only in classes meant to act as interfaces to objects of derived classes (typically allocated on a heap and accessed through pointers or references).
So when should I declare a destructor virtual? Whenever the class has at least one virtual function. Having virtual functions indicate that a class is meant to act as an interface to derived classes, and when it is, an object of a derived class may be destroyed through a pointer to the base.

Why don't we have virtual constructors?
A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a function knowing only an interfaces and not the exact type of the object. To create an object you need complete information. In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.
Techniques for using an indirection when you ask to create an object are often referred to as "Virtual constructors". For example, see TC++PL3 15.6.2.

多态：
静态多态：函数重载，范型编程
动态多态：虚函数

override->重写(=覆盖)、overload->重载、polymorphism -> 多态
 
override是重写（覆盖）了一个方法，以实现不同的功能。一般是用于子类在继承父类时，重写（重新实现）父类中的方法。
overload是重载，一般是用于在一个类内实现若干重载的方法，这些方法的名称相同而参数形式不同。
多态：允许将子类类型的指针赋值给父类类型的指针，可以调用子类的实现。

对象初始化过程中，主要涉及三种执行对象初始化的结构，分别是 实例变量初始化、实例代码块初始化 以及 构造函数初始化。

type_traits是编译期就去确定具体的类型，从而根据不同的类型来执行不同的模块，消除重复，提高代码质量。

迭代器（iterator）是一种抽象的设计概念。可以在不知道数据容器的具体结构的情况下，对数据结构进行操作，作为粘合剂将容器和算法集合在一起。

```c++
//true
cout << "int, const int " << std::is_same<int, const int>::value << endl;

//false
cout << "int, decay(const int) " << std::is_same<int, typename decay<const int>::type>::value << endl;
```