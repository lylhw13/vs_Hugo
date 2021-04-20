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



第一设计范式:  所有属性不可以再划分，用于保证列的原子性

聚集索引和非聚集索引：

With a clustered index the rows are stored physically on the disk in the same order as the index. Therefore, there can be only one clustered index.

With a non clustered index there is a second list that has pointers to the physical rows. You can have many non clustered indices, although each new index will increase the time it takes to write new records.

It is generally faster to read from a clustered index if you want to get back all the columns. You do not have to go first to the index and then to the table.

Writing to a table with a clustered index can be slower, if there is a need to rearrange the data.

- 一个进程至少有一个线程，线程作为调度的基本单位。
- 线程共享父进程申请到的内存空间，但并不代表，共享父进程的栈空间。
- 线程必须从属于一个进程，并且是不可变更的。

主线程改变会影响到其他线程；
线程之间可以直接通信，但是进程之间必须通过IPC

多进程中每一个进程都拥有自己的地址空间，而线程都共享同一个地址空间。

TCP是面向连接的可靠的服务
TCP是端对端的，不支持多播，UDP才支持多播

动态链接库dll的共享部分包括代码段和外部定义的引用

内连接返回的结果集是两个表中所有相匹配的数据，不包含没有匹配的行。
外连接有三种：左外连接，右外连接，全外连接。外连接不仅包含符合连接条件的行，还包含左表（左外连接）、右表（右外连接）或两个表（全外连接）中的所有数据行。对于没有匹配的行就用NULL值来填充。
因此，外连接中：既包含相匹配的行也包括不相匹配的行、不相匹配的行就用NULL值填充、外连接中也可以只有不匹配的行。

```txt
$$
Shell本身的PID（ProcessID）
$!
Shell最后运行的后台Process的PID
$?
最后运行的命令的结束代码（返回值）
$-
使用Set命令设定的Flag一览
$*
所有参数列表。如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。
$@
所有参数列表。如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。所以适合绝大多数情况。
$#
添加到Shell的参数个数
$0
Shell本身的文件名
$1～$n
添加到Shell的各参数值。$1是第1参数、$2是第2参数…
```

分级调度算法是结合时间片轮转调度算法一起使用的，这种算法的本质是链入多个队列，当进程消耗完时间片但是它的工作尚未结束时，它就会被链入下一级队列，第一级队列的优先级最高，但是第一级队列的进程分配的时间片都很小，于是很快就轮转完了，队列等级越往下，时间片分配的就越多。

选码的定义：若关系中的某一属性组的值能唯一地标识一个元组（表中的一行数据），则称该属性组为候选码。

CREATE INDEX indexName ON mytable(username(length)); 
如果是CHAR，VARCHAR类型，length可以小于字段实际长度；如果是BLOB和TEXT类型，必须指定 length。

因为+是双目运算符，但是函数里只传了一个参数，就必然使用了this指针，那就肯定不是友元函数了

TCP支持的应用协议：TELNET（远程终端登录协议）,FTP（文件传输协议）,SMTP（简单邮件传送协议）,HTTP（传送协议）
UDP支持的应用协议：NFS(网络文件系统)，SNMP（简单网络管理协议），DNS（域名服务），TFTP（简单文件传输协议）

只要记住，有连接的一定要确认
数据链路层一般都提供3种基本服务，即无确认的无连接服务、有确认的无连接服务、有确认 的面向连接的服务。 
1. 无确认的无连接服务 无确认的无连接服务是源机器向目的机器发送独立的帧，而目的机器对收到的帧不作确认。 如果由于线路上的噪声而造成帧丢失，数据链路层不作努力去恢复它，恢复工作留给上层去完成。 这类服务适用于误码率很低的情况，也适用于像语音之类的实时传输，实时传输情况下有时数据延误比数据损坏影响更严重。 大多数局域网在数据链路层都使用无确认的无连接服务。 
2. 有确认的无连接服务 这种服务仍然不建立连接，但是所发送的每一帧都进行单独确认。 以这种方式，发送方就会知道帧是否正确地到达。如果在某个确定的时间间隔内，帧没有到达，就必须重新发此帧。 
3. 有确认的面向连接的服务 采用这种服务，源机器和目的机器在传递任何数据之前，先建立一条连接。 在这条连接上所发送的每一帧都被编上号，数据链路层保证所发送的每一帧都确实已收到。 而且，它保证每帧只收到一次，所有的帧都是按正确顺序收到的。面向连接的服务为网络进程间提供了可靠地传送比特流的服务。

生成树协议（英语：Spanning Tree Protocol，STP），是一个作用在OSI（Open System Interconnection Model）网络模型中第二层的通信协议。基本应用是防止交换机冗余链路产生的环路，用于确保以太网中无环路的逻辑拓扑结构，从而避免广播风暴大量占用交换机的资源。

码率 mbps是Million bits per second的缩写，是一种传输速率单位，指每秒传输的位（比特）数量。所以需要转化为 byte 的传输速度，需要除以 8。

哈夫曼树只是一棵最优二叉树，不一定是完全二叉树，也不一定是平衡二叉树哈夫曼树不关注树的结构，只关注带权路径长度

In computer science, an AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree.
在计算机科学中，AVL树是最早被发明的自平衡二叉查找树。在AVL树中，任一节点对应的两棵子树的最大高度差为1，因此它也被称为高度平衡树。

拓扑序列是顶点活动网中将活动按发生的先后次序进行的一种排列。
该排列满足：如果图中有一条从u到v的路径，则顶点v必须出现在顶点u之后。找出顶点活动网中的拓扑序列称“拓扑排序”。

BFS和DFS都是：
邻接矩阵-O(n^2)
邻接表-O(n+e)

C/C++ does not do boundary checking when using arrays.
数组和整形之间留有两个间隙。

私有成员调用，需要加上该私有成员的的归属类。

三目运算符 ? : 的优先级是要低于 << 的。

Array comparison always evaluates to false
数组比较最后变成指针地址的比较

IOS C++11 does not allow conversion from string literal to 'char*'.

DNS服务器主配置文件：  /etc/named.conf