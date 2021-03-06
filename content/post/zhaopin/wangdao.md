---
title: "Wangdao"
date: 2020-06-28T19:50:15+08:00
draft: true
---

# chapter 1
数组首地址是常量，不能赋值操作。

sizeof 不是一个函数，它的计算发生在编译时刻，所以它可以被当作常量表达式使用，且会忽略其括号内的各种运算，如"sizeof()"中的++不执行。

结构体里面有数组时，不进行对齐。

空结构体，空类大小为1

enum只是定义了一个常量集合，里面没有“元素”，而枚举类型是当作int类型存储的，故枚举类型的sizeof值为4。

static作用：
1. 隐藏
2. 默认初始化为0
   初始化的静态变量存储在data段，未初始化的静态变量存储在BSS段。正因此如此，才可以持久
3. 保持局部变量段持久

static数据成员必须在类定义体的外部定义，
但是const static可以在类内定义。

静态成员函数，无法访问属于类对象的非静态数据成员，也无法访问非静态成员函数。

仅仅依靠返回值类型不能区别重载函数。
重载和成员函数是否是虚函数无关。

类层次间的下行转换是不能通过隐式转换完成的。
仅当类型之间可隐式转换时（除类层次间的下行转换以外），static_cast的转换才是合法的，否则将出错。

## 8 class
类中的每个成员，使用与初始化变量相同的规则来进行初始化：
1. 类成员：运行该类型的默认构造函数来初始化
2. 内置或复合类型的成员的初始值依赖于对象的作用域
   1. 在局部作用域中这些成员不被初始化
   2. 在全局作用域中它们被初始化为0
   
在C++中，成员变量的初始化顺序与在变量在类型中的声明顺序相同，而与它们在构造函数的初始化列表中的顺序无关。

### 为什么拷贝构造函数的参数是一个引用，可以不是引用吗？
如果不是引用，就相当于采用了传值的方式，而传值的方式会调用该类的拷贝构造函数，从而造成无穷递归地调用拷贝构造函数。因此拷贝构造函数的参数必须是一个引用。

### 深复制，浅复制
浅复制仅复制所考虑的对象，而不复制它所引用的对象。
深复制要把要复制的对象引用的对象都复制一遍。

派生类构造函数的调用顺序：
1. 完成对象所占整块内存的开辟，由系统在调用构造函数时自动完成
2. 调用基类的构造函数完成基类成员的初始化
3. 派生类的类成员初始化
4. 派生类构造函数体执行

C++,中，下面的操作符是不能被重载的：
- ::  (域操作符)
- .   (成员访问或点操作符)
- .* (指向成员的指针操作符)
- ?: (三元操作符或条件操作符)
- sizeof (取对象大小操作符)
- typeid (对象类型操作符)

基类的构造函数（包括拷贝构造函数）、析构函数、赋值操作符重载函数，都不能被派生类继承。

小端，低地址中存放的是字数据的低字节，所以最先遇到低字节。

### 基类成员在派生类中的访问属性
- 派生类的对象，只能访问通过 public 方式继承的基类的 public 成员。
- 派生类不能看见基类的 private 成员, 可以访问其他成员。
- 从基类继承来的成员在派生类中的访问属性为：min（继承方式，基类中的访问属性）。
  private < protected < public


### 如何限制栈对象的生成？如何限制堆对象的生成？
1. 限制堆对象的生成：
   将 operator new 和 operator delete 重载为 private。栈对象不受影响。
2. 限制栈对象的生成：
   将构造函数和析构函数设为私有的。堆对象不受影响。

一个类只能有一个析构函数


# chaper 2
网卡：既工作在物理层，也工作在数据链路层的mac子层。
交换机：一般工作在数据链路层，也有工作在网络层的，这些交换机成为第三层交换机。
路由器：工作在网路层。

TCP为每个连接总共建立七个定时器：
- 连接建立（connection establishment）定时器
- 重传（retransmission）定时器
- 延迟ACK（delayed ACK）定时器
- 持续（persist）定时器
- 保活（keep alive）定时器
- FIN_WAIT_2定时器
- TIME_WAIT定时器

32bit全为0，既 0.0.0.0表示整个TCP/IP网络
32bit全为1，既 255.255.255.255表示整个TCP/IP网络的广播地址

网络地址转换（NAT）是通过将专用网络地址（如企业内部网）转换为公用地址，从而对外隐藏了内部管理的IP地址。也解决来IP4地址不足的问题。

私有IP地址网段为：
10.0.0.0 ~ 10.255.255.255
172.16.0.0 ~ 172.31.255.255
192.168.0.0 ~ 192.168.255.255

子网需要再记忆 p323

无分类编址 CIDR，这种地址的聚合称为路由聚合，或称为超网。
IP地址/网络前缀所占比特数

地址解析协议（Address Resolution Protocol，ARP），将IP地址转换为MAC地址。每台主机（路由器）上单独存放一个从IP地址到MAC地址的映射表，称为ARP表。主机和路由器使用地址解析协议ARP来动态维护此ARP表。
物理地址转IP地址用RARP（Reverse Address Resolution Protocol）。

为了提高IP数据报文成功交付的机会，在网络层使用来网际控制报文协议（Internet Control Message Protocol， ICMP）来是的主机和路由器可以报告差错和异常情况。
PING命令工作在应用层，它直接使用网络层的ICMP协议，而没有使用传输层的TCP或UDP协议。

```sh
tracert

telnet

netstat
```

# chapter 3
操作系统的四个特征：并发，共享，异步，虚拟。

操作系统的并发性是通过分时得以实现的。

资源共享有两种方式：互斥访问和同时访问。

进程一般有五种状态：
- 运行状态
- 就绪状态  当一个运行进程被剥夺处理机时，例如时间片用完，其状态由运行变为就绪。
- 阻塞状态
- 创建状态
- 结束状态 不属于进程的基本状态
  
程序是静态概念
进程是动态概念


线程是进程中的一个实体，是被系统独立调度和分派的基本单位。

线程有就绪，阻塞和运行三种基本状态。

线程是独立调度的基本单位，进程是拥有资源的基本单位。

一次仅允许一个进程使用的资源称为临界资源。访问临界资源的那段代码称为临界区（critical section）。

消息队列克服了信号承载信息量少，管道只能承载无格式字节流以及缓冲区大小受限等缺点。

临界区（critical section）与互斥体（mutex）的区别：
1，临界区只能用来同步进程内的线程，而不可用来同步多个进程中的线程；互斥量（mutex），信号量（semaphore），事件（event）都可以被跨越进程使用来进行同步数据操作。
2，临界区是非内核对象，只在用户态进行锁操作，速度快；互斥体是内核对象，在核心态进行锁操作，速度慢。
3，临界区和互斥体在windows平台下可用，linux下只用互斥体可用。

# vector可以存引用吗

vector 不可以存引用：引用不支持一般意义上的赋值操作
- references are not objects 引用不是对象
- can't rebind a reference, references must be initialized 引用不能赋值，只能初始化

