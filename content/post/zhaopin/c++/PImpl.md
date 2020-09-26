---
title: "PImpl"
date: 2020-09-26T17:31:56+08:00
draft: true
---

PImpl, Pointer to implementation
通过降低类的使用者和类定义之间的依赖，来减少编译时间。
简单来说，就是在头文件定义一个不完整的结构体名称，然后在另外一个文件中进行实现。

gadget.h

```c++
#ifndef gadget_h
#define gadget_h
class Gadget{};
#endif
```

widget.h
```c++
#ifndef widget_h
#define widget_h
#include <memory>

class Widget{
public:
    Widget();
    ~Widget();  // 防止自动生成
    
    Widget(Widget&& rhs);   // move
    Widget& operator=(Widget&& rhs);
    
    Widget(const Widget& rhs) = delete; // copy
    Widget& operator=(const Widget& rhs) = delete;
    
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif
```

widget.cpp

```c++
#include "widget.h"
#include "gadget.h"

struct Widget::Impl{
    Gadget g1, g2, g3;
};

Widget::Widget():pImpl(std::make_unique<Impl>()){
}

Widget::~Widget() = default;
Widget::Widget(Widget&& rhs) = default;
Widget& Widget::operator=(Widget&& rhs) = default;
```