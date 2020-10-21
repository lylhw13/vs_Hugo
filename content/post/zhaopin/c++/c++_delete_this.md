---
title: "C++_delete_this"
date: 2020-10-15T22:41:33+08:00
draft: true
---
总结：
- 成员函数可以持有 delete this，但是只能用在 new 出的对象上。
- 析构函数不能持有 delete this，会造成循环调用，直到内存溢出。
  
```c++
class A{
public:
    void fun(){
        delete this;
    }
    ~A(){
        cout << "~A" << endl;
        //delete this;
    }
};

A* a = new A;
a->fun();        // ok

A* a = new A;
a->fun();
delete a;           // free(): double free detected

A a;
a.fun();        
return;           // free(): invalid pointer
```

```c++
class A{
public:
    void fun(){
        delete this;
    }
    ~A(){
        cout << "~A" << endl;
        delete this;
    }
};

A* a = new A;
a->fun();       // 循环调用析构函数，直到内存溢出

A* a = new A;
delete a;       // 循环调用析构函数，直到内存溢出

A a;
return;         // 离开作用域，循环调用析构函数，直到内存溢出

A a;
a.fun();
return;         // 离开作用域，循环调用析构函数，直到内存溢出
```