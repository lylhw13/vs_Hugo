---
title: "The_Essence_of_C++"
date: 2019-10-30T14:23:41+08:00
draft: true
---

- "Resource Acquisition Is Initialization"(RAII)
    - Acquire during construction
    - Release in destructor
- Throw exception in case of failure
    - In particular, throw is a constructor cannot construct and object
- Never throw while hoding a resource not owned by a handle
    - Never leak
- In general
    - Leave established invariants intact whne leaving a scope.
