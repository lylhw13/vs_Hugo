---
title: "Requiring or Prohibiting Heap-based Objects"
date: 2020-10-24T09:39:57+08:00
draft: true
---

要求或禁止在堆上生产对象


```c++
class OnlyHeap{
public:
    void destory() const{
        delete this;
    }
protected:
    ~OnlyHeap(){}
};

class NoHeap{
protected:
    static void* operator new(size_t);  // #1: To prevent allocation of scalar objects
    static void* operator new[](size_t);    // #2: To prevent allocation of array of objects
};
```