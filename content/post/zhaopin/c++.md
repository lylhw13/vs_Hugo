---
title: "C++"
date: 2020-06-18T22:52:49+08:00
draft: true
---

# c++11 新特性
- “语法糖”：nullptr, auto自动类型推导，范围for循环，初始化列表, lambda表达式等
- 右值引用和移动语义
- 智能指针
- C++11多线程编程：thread库及其相配套的同步原语mutex, lock_guard, condition_variable, 以及异步std::furture

# C++面向对象的三种特性？（每条详细说说）
   面向对象的三个基本特征是：封装、继承、多态。
   封装，也就是把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。
   面向对象编程 (OOP) 语言的一个主要功能就是“继承”。继承是指这样一种能力：它可以使用现有类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。
   多态性（polymorphisn）是允许你将父对象设置成为和一个或更多的他的子对象相等的技术，赋值之后，父对象就可以根据当前赋值给它的子对象的特性以不同的方式运作。简单的说，就是一句话：允许将子类类型的指针赋值给父类类型的指针。

# 多态：
- 静态多态：函数重载，范型编程
- 动态多态：虚函数

override->覆盖、overload->重载、polymorphism -> 多态

Only virtual member functions can be marked 'override'
override 覆盖，是指子类重新定义父类的`虚函数`的做法。参数列表不同被认为是不同的函数。如果参数列表相同，则返回类型必须相同。
overload 重载，是指允许存在多个同名函数，而这些函数的参数表不同。不能仅仅依靠返回值来区分。
在继承中，对于非虚函数，如果函数名相同，则会产生隐藏，此时不需要返回值相同。

多态：允许将子类类型的指针赋值给父类类型的指针，可以调用子类的实现。
当你用继承的时候，肯定是需要利用多态的特性。如果用不到多态的特性，继承的关系是无用的。
多用组合，少用继承。


type_traits是编译期就去确定具体的类型，从而根据不同的类型来执行不同的模块，消除重复，提高代码质量。

迭代器（iterator）是一种抽象的设计概念。可以在不知道数据容器的具体结构的情况下，对数据结构进行操作，作为粘合剂将容器和算法集合在一起。

```c++
//true
cout << "int, const int " << std::is_same<int, const int>::value << endl;

//false
cout << "int, decay(const int) " << std::is_same<int, typename decay<const int>::type>::value << endl;
```


# POD (plain old data)
C++98 不允许联合体的成员是非 POD 类型，但是 C++11 取消了这种限制。

POD 类型一般具有以下几种特征（包括 class、union 和 struct等）：

1) 没有用户自定义的构造函数、析构函数、拷贝构造函数和移动构造函数。
2) 不能包含虚函数和虚基类。
3) 非静态成员必须声明为 public。
4) 类中的第一个非静态成员的类型与其基类不同，例如：
class B1{};
class B2 : B1 { B1 b; };
class B2 的第一个非静态成员 b 是基类类型，所以它不是 POD 类型。

5) 在类或者结构体继承时，满足以下两种情况之一：
派生类中有非静态成员，且只有一个仅包含静态成员的基类；
基类有非静态成员，而派生类没有非静态成员。

# extern "C"
name mangling
被 extern 限定的函数或变量是 extern 类型的
被 extern "C" 修饰的变量和函数是按照 C 语言方式编译和链接的
extern "C" 的作用是让 C++ 编译器将 extern "C" 声明的代码当作 C 语言代码处理，可以避免 C++ 因符号修饰导致代码不能和C语言库中的符号进行链接的问题。

由于C++支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型，一般之包括函数名。

# volatile

# Dangling pointers and wild pointers 空悬指针和野指针
- 指针变量未初始化
- 指针被free后，没有置为NULL
- 指针指向栈内存

# share_ptr
智能指针的线程安全性

# vector 底层实现

# c++ 内存泄漏及检测方法

主要关注两类内存泄漏：
1. 堆内存泄漏 （Heap leak）。对内存指的是程序运行中根据需要分配通过malloc,realloc new等从堆中分配的一块内存，再是完成后必须通过调用对应的 free或者delete 删掉。如果程序的设计的错误导致这部分内存没有被释放，那么此后这块内存将不会被使用，就会产生Heap Leak. 

2. 系统资源泄露（Resource Leak）.主要指程序使用系统分配的资源比如 Bitmap,handle ,SOCKET等没有使用相应的函数释放掉，导致系统资源的浪费，严重可导致系统效能降低，系统运行不稳定。

可以使用以下两种方式，进行检查排除:
1. 使用工具软件BoundsChecker，BoundsChecker是一个运行时错误检测工具，它主要定位程序运行时期发生的各种错误。
2. 调试运行DEBUG版程序，运用以下技术：CRT(C run-time libraries)、运行时函数调用堆栈、内存泄漏时提示的内存分配序号(集成开发环境OUTPUT窗口)，综合分析内存泄漏的原因，排除内存泄漏。

避免方法：
1. 使用智能指针进行避免
2. RAII，资源获取即初始化，Resource Acquisition Is Initialization

# 线程池实现

# 绝不能在构造和析构过程中调用virtual函数

因为derived class对象内的base class 成分会在derived class 自身成分被构造之前先构造妥当。base class 构造期间的 virtual 函数绝不会下降到 derived class阶层。

因此，此时 derived class在构造和析构内的virtual函数，其实调用的是 base class 的版本。

# 析构函数要声明为virtual 函数


# Why are member functions not virtual by default? or Why are destructors not virtual by default?

Because many classes are not designed to be used as base classes. Virtual functions make sense only in classes meant to act as interfaces to objects of derived classes (typically allocated on a heap and accessed through pointers or references).

Q: 为何成员函数不是默认为虚？
A: 因为许多类不是被用来做基类的。 例如，复数类就是如此。
另外，有虚函数的类有虚机制的开销[译注：指存放vtable带来的空间开销和通过vtable中的指针间接调用带来的时间开销]，通常而言每个对象增加的空间开销是一个字长。这个开销可不小，而且会造成和其他语言（比如C，Fortran）的不兼容性——有虚函数的类的内存数据布局和普通的类是很不一样的。[译注：这种内存数据布局的兼容性问题会给多语言混合编程带来麻烦。]

# Why don't we have virtual constructors?
A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a function knowing only an interfaces and not the exact type of the object. To create an object you need complete information. In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.

# Can I call a virtual function from a constructor?
Yes, but be careful. It may not do what you expect. In a constructor, the virtual call mechanism is disabled because overriding from derived classes hasn't yet happened. Objects are constructed from the base up, "base before derived".

Destruction is done "derived class before base class", so virtual functions behave as in constructors: Only the local definitions are used - and no calls are made to overriding functions to avoid touching the (now destroyed) derived class part of the object.

# 实例化一个对象需要那几个阶段？
三个阶段: 分配空间，初始化，赋值

对象初始化过程中，主要涉及三种执行对象初始化的结构，分别是 实例变量初始化、实例代码块初始化 以及 构造函数初始化。

# static 关键字

C语言：
1. 用于函数内部修饰变量，起到持久化的作用。
2. 用在文件级别（函数体外），修饰变量或函数，表示该变量或函数只在本文件可见。起到隐藏的作用。
C++引入class，在保持和C语言兼容的同时，又添加两种新用法
3. 用于修饰class的数据成员，即所谓“静态成员”。静态数据成员每个class只有一份
4. 用于修饰class的成员函数，即所谓“静态成员函数”。这种函数只能访问静态成员和静态成员函数。

# 纯虚函数

声明在头文件中的虚函数，在分号前使用=0，则为纯虚函数。纯虚函数不需要定义。
含有纯虚函数的类为抽象类。如果子类也没有为纯虚函数定义，则也为纯虚函数。抽象类不能被实例化。


# const 原理
所有标记上const的指针/引用/变量是不会有什么运行时保护的，只有编译的时候做检查而已。

至于const char* x="abcde";为什么VC++有保护，那是因为"abcde"被编译在了一个readonly的memory page上面，跟x声明成const char*是没关系的。如果这时候使用const_cast进行改写，程序会崩溃。

如果是const传递的c++对象，const_cast后改写没什么问题。

# 智能指针线程安全

unique_ptr 和 shared_ptr 都不是线程安全的。

shared_ptr 有两个数据成员，因此读写操作不能原子化。 shared_ptr 的线程安全级别和内建类型、标准库容器、std::string 一样。
1. 一个shared_ptr实例被多个线程同时读取
2. 不同的shared_ptr的实例被不同的线程同时写入
3. 任何其他的情况都会导致未定义的行为。
   
可以使用 `std::atomic<std::shared_ptr>>`来达到线程安全的目的。

All C/C++ Operations Are Presumed Non-Atomic

# 仿函数

 仿函数(functor)，就是使一个类的使用看上去象一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了。
```c++
struct add_x {
        add_x(int val) : x(val) {}  // Constructor
        int operator()(int y) const { return x + y; }

    private:
        int x;
};
// Now you can use it like this:
add_x add42(42); // create an instance of the functor class
int i = add42(8); // and "call" it
assert(i == 50); // and it added 42 to its argument
```
仿函数就像闭包一样，可以包含状态。


# 接口继承 C++是怎么实现接口的

- 不继承实现，只继承方法接口：纯虚函数。
- 继承方法接口，以及默认的实现：虚函数。
- 继承方法接口，以及强制的实现：普通函数。


# 协程
没有太多接触，个人理解是更轻量级的线程，不需要内核参与进行调度。

# 统计房间人数多少
编程珠玑里面有算法
little定律：
系统中物体的平均数量等于离开系统的平均速率和每个物体在系统中停留的平均时间的乘积。
简要描述为：队列中物体的平均数量为进入速率与平均停留时间的乘积。

# RPC

# 简历介绍

具备扎实的计算机、网络等方面的基础知识
有扎实的c/c++ 编程能力，有良好的数据结构和算法基础；
有Windows或mac客户端的开发经验；有平台相关的调试/调优经验；
对网络安全、信息安全等有一定了解
熟悉TCP/IP协议，熟练掌握Linux网络编程和多线程编程技术；

有大型软件开发维护经验




# struct中长度为零的数组
struct 一个长度为0的数组，又叫柔性数组，只能放在结构体末尾，它可以使得这个结构体是可变长的。
对于编译器来说，此时长度为0的数组并不占用空间，因为数组名本身不占空间，它只是一个偏移量， 数组名这个符号本身代表了一个不可修改的地址常量。

# volatile  atomic
特殊内存，比如 内存映射IO（memory-mapped I/O）

atomic 适合并发编程，但不适合特殊内存，volatile 刚好相反，两者可以搭配使用
atomic 可以用来无锁编程

atomic：
- 保证atomic对象的所有成员函数是原子的
- 保证指令不重排

atomic 的拷贝构造，拷贝赋值，移动构造，移动赋值都不具有原子性，都被编译器删除。

```c++
std::atomic<int> x;

std::cout << x; //只能保证读取到x的值是原子的，但不保证输出这个动作是原子的
++x;        //这个动作属于 RMW（read modify write）是原子的

auto y = x; //这句编译不能通过，因为复制不能是原子的，所以拷贝构造函数被编译器删除

std::atomic<int> y(x.load());
```

volatile：
- 保证冗余的读和写不被优化

# c++ 构造函数的调用时机
- 如果是全局对象，则在 main() 函数之前调用

crt: C runtime

crt0 是连接到C程序上的一组执行启动例程，它进行在调用这个程序的主函数之前所需要的任何初始化工作。它一般的都采用叫做crt0.o的目标文件形式，经常采用汇编语言编写，链接器自动的将它包括入它所建造的所有可执行文件中。

crt1 是在 crt0 的基础上支持构造函数和析构函数（这些函数在main之前，exit 之后调用）。这种情况下，main就像一个普通的函数调用。

crt0/crt1 都是用来实现在调用main() 之前的一些初始化工作（比如，初始化栈）。

Both crt0/crt1 do the same thing, basically do what is needed before calling main() (like initializing stack, setting irqs, etc.). You should link with one or the other but not both. They are not really libraries but really inline assembly code.

As far as I understand, crt comes in two "flavors"

crt1 is used on systems that support constructors and destructors (functions called before and after main and exit). In this case main is treated like a normal function call.
crt0 is used on systems that do not support constructors/destructors.

