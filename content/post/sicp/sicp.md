---
title: "Structure and Interpreation of Computer Programs"
date: 2019-07-12T22:26:39+08:00
draft: true
---


前缀表示的优点之一是：
- 完全适用于可能带有任意个实参的过程。
- 可以直接扩充

the Scheme dialect of Lisp

## 1.1
procedures and data

### 1.1.1

parentheses

combinations 

operator 运算符
operands 运算对象

arguments

Prefix notation:
- can accommodate procedures that may take an arbitrary number of arguments
- it extends in a straightforward way to allow combinations to be nested

read-evaluate-print-loop (REPL)

pretty-printing

### 1.1.3 Evaluating Combinations
1. Evaluate the subexpressions of the combination.
2. Apply the procedure that is the value of the leftmost subexpression (the operator) to the arguments that are the values of the other subexpressions (the operands).

special forms

### 1.1.4 Compound Procedures

procedure definitions

```lisp
(define (<name> <formal parameters>) <body>)
```

### 1.1.5 The Substitution Model for Procedure Application

normal-order evaluation: fully expand and then reduce

applicative-order evaluation: evaluate the arguments and then apply, which is interpreter actually uses.

Lisp uses applicative-order evaluation

### 1.1.6 Conditional Expressions and Predicates

case analysis

```lisp
(define (abs x) 
  (cond ((> x 0) x) 
        ((= x 0) 0)
        ((< x 0) (- x))))
```
This process continues until a predicate is found whose value is true, in which case the interpreter returns the value of the corresponding consequent expression ⟨e⟩ of the clause as the value of the conditional expression.
If none of the ⟨p⟩’s is found to be true, the value of the cond is undefined.

Notice that and and or are special forms, not procedures, because the subexpressions are not necessarily all evaluated.

### 1.1.7 Example: Square Roots by Newton's Method

