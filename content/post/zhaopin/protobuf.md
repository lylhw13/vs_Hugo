---
title: "Protobuf"
date: 2020-08-19T10:36:06+08:00
draft: true
---
参考：https://www.ibm.com/developerworks/cn/linux/l-cn-gpb/

# 序列化 和 反序列化

- 序列化： 将数据结构或对象转换成二进制串的过程
- 反序列化：将在序列化过程中所生成的二进制串转换成数据结构或者对象的过程

序列化方案中，按照存储方案，可分为字符串存储和二进制存储：
- 字符串存储是可读的，但是会面临数据放大问题，即 JSON 和 XML 使用字符串表示所有的数据，对于非字符数据来说，字面量表达会占用很多存储空间，对数据解析也十分低效。在面对海量数据时，这种格式本身就能够成为整个系统的 IO 与计算瓶颈。

# Protobuf
优点：
1. 以二进制方式存储，体积小，性能高
2. 向后兼容性好
3. 只需使用 Protobuf 对数据结构进行一次描述，即可利用各种不同语言或从各种不同数据流中对你的结构化数据轻松读写。
缺点：
1. Protbuf 与 XML 相比也有不足之处。它功能简单，无法用来表示复杂的概念。
2. 由于 XML 具有某种程度上的自解释性，它可以被人直接读取编辑，在这一点上 Protobuf 不行，它以二进制的方式存储，除非你有 .proto 定义，否则你没法直接读出 Protobuf 的任何内容。


技术细节：
1. 采用 Varint 编码的方法表示数字。Varint 是一种紧凑的表示数字的方法。它用一个或多个字节来表示一个数字，值越小的数字使用越少的字节数。这能减少用来表示数字的字节数。
2. XML 需要从文件中读取出字符串，再转换为 XML 文档对象结构模型。之后，再从 XML 文档对象结构模型中读取指定节点的字符串，最后再将这个字符串转换成指定类型的变量。这个过程非常复杂，其中将 XML 文件转换为文档对象结构模型的过程通常需要完成词法文法分析等大量消耗 CPU 的复杂计算。
反观 Protobuf，它只需要简单地将一个二进制序列，按照指定的格式读取到 C++ 对应的结构类型中就可以了。从上一节的描述可以看到消息的 decoding 过程也可以通过几个位移操作组成的表达式计算即可完成。速度非常快。

# proto 文件
```proto
package lm; 
message helloworld 
{ 
   required int32     id = 1;  // ID 
   required string    str = 2;  // str 
   optional int32     opt = 3;  //optional field 
}
```

```c++
#include "lm.helloworld.pb.h"
int main(void) 
{ 

lm::helloworld msg1; 
msg1.set_id(101); 
msg1.set_str(“hello”); 
    
// Write the new address book back to disk. 
fstream output("./log", ios::out | ios::trunc | ios::binary); 
        
if (!msg1.SerializeToOstream(&output)) { 
    cerr << "Failed to write msg." << endl; 
    return -1; 
}         
return 0; 
}
```

```c++
#include "lm.helloworld.pb.h" 
void ListMsg(const lm::helloworld & msg) { 
cout << msg.id() << endl; 
cout << msg.str() << endl; 
} 

int main(int argc, char* argv[]) { 

lm::helloworld msg1; 

    { 
    fstream input("./log", ios::in | ios::binary); 
    if (!msg1.ParseFromIstream(&input)) { 
        cerr << "Failed to parse address book." << endl; 
        return -1; 
    } 
} 

ListMsg(msg1); 
}
```