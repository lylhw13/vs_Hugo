---
title: "C++_primer"
date: 2019-03-07T15:09:15+08:00
draft: true
---

## chapter 6

Array have two special properties:  `p214`
- we cannot copy an array.
- when we use an array it is (usually) converted to a pointer.


## chapter 7
```c++
//p294
Sales_data obj();           // opps! declares a function, not an object
Sales_data obj2;            // ok: obj2 is an object, not a function
```
A constructor that can be called with a single argument defines an implicit conversion from the constrctos's parameter type to the class type. `p295`

- The string constrctor that takes a single parameter of type const char* is not explicit.
- The vector constrctor that takes a size is explicit.    `p297`

when we define a member outside the class, we do not repeat the keyword:
- explicit      `p296`
- static        `p302`