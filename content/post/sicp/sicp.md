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

```lisp
(cond (⟨p1⟩ ⟨e1⟩) 
      (⟨p2⟩ ⟨e2⟩)
      ...
      (⟨pn⟩ ⟨en⟩))
```

This process continues until a predicate is found whose value is true, in which case the interpreter returns the value of the corresponding consequent expression ⟨e⟩ of the clause as the value of the conditional expression.
If none of the ⟨p⟩’s is found to be true, the value of the cond is undefined.

Notice that and and or are special forms, not procedures, because the subexpressions are not necessarily all evaluated.

### 1.1.7 Example: Square Roots by Newton's Method

mathermatical functions
computer procedures

### 1.1.8 Procedures as Black-Box Abstractions

procedural abstraction
local names
bound variable
lexical scoping 词法作用域

## 1.2 Procedures and the Processes They Generate

The ability to visualize the consequences of the actions under con- sideration is crucial to becoming an expert programmer, just as it is in any synthetic, creative activity. 

### 1.2.1 Linear Recursion and Iteration

The expansion occurs as the process builds up a chain of deferred operations (in this case, a chain of multiplications). The contraction occurs as the operations are actually performed. 
This type of process, characterized by a chain of deferred operations, is called a recursive process.

In general, an iterative process is one whose state can be summarized by a fixed number of state variables

linear recursive process
linear iterative process

### 1.2.2 Tree Recursion

### 1.2.3 Orders of Growth

### 1.2.4 Exponentiation

### 1.2.5 Greatest Common Divisors
GCD
Euclid’s Algorithm 欧几里得算法

Lamé’s Theorem: If Euclid’s Algorithm requires k steps to compute the GCD of some pair, then the smaller number in the pair must be greater than or equal to the k<sup>th</sup> Fibonacci number.

### 1.2.6 Example: Testing for Primality

Fermat’s Little Theorem: If n is a prime number and a is any positive integer less than n, then a raised to the n<sup>th</sup> power is congruent to a modulo n.

probabilistic algorithms

## 1.3 Formulating Abstractions with Higher-order Procedures

higher-order procedures

### 1.3.1 Procedures as Arguments

### 1.3.2 Constructing Procedures Using lambda

```lisp
(lambda (<formal-prarmeter>) <body>)

(let ((⟨var1⟩ ⟨exp1⟩) 
      (⟨var2⟩ ⟨exp2⟩)
      ...
      (⟨varn⟩ ⟨expn⟩)) 
    ⟨body⟩)

((lambda(⟨var1⟩ ... ⟨varn⟩) 
    ⟨body⟩)
  ⟨exp1⟩ 
  ... 
  ⟨expn⟩)
```

A let expression is simply syntactic sugar for the un- derlying lambda application.

The variables’ values are computed outside the let.

### 1.3.3 Procedures as General Methods

half-interval

fixed point

-> (pronounced “maps to”) is the mathematician’s way of writing lambda. y -> x /y means(lambda (y) (/ x y)), that is, the function whose value at y is x/y.

This approach of averaging successive approximations to a solution, a technique that we call `average damping`, often aids the convergence of fixed-point searches.

### 1.3.4 Procedures as Returned Values

Newton's method

Abstractions and first-class procedures

Lisp, unlike other common programming languages, awards procedures full first-class status.

# chapter 2 Building Abstractions with Data

The general technique of isolating the parts of a program that deal with how data objects are represented from the parts of a program that deal with how data objects are used is a powerful design methodology called data abstraction.

## 2.1 Introduction to Data Abstraction

selectors and constructors

### 2.1.1 Example: Arithmetic Operations for Rational Numbers

numberator
denominator

### 2.1.2 Abstraction Barriers
In effect, procedures at each level are the interfaces that define the abstraction barriers and connect the different levels.

### 2.1.3 What is Meant by Data?

procedural representations of data will play a central role in our programming repertoire. This style of programming is often called message passing.

### 2.1.4 Extended Exercise: Interval Arithmetic

## 2.2 Hierachical Data and the Closure Property

box-and-pointer notation

closure property

Closure is the key to power in any means of combination because it permits us to create hierarchical structures.

### 2.2.1 Representing Sequences
The cdr of the final pair signals the end of the sequence by pointing to a distinguished value that is not a pair, represented in box-and-pointer diagrams as a diagonal line and in programs as the value of the variable nil.

list

In this book, we use list to mean a chain of pairs terminated by the end-of-list marker. In contrast, the term list structure refers to any data structure made out of pairs, not just to lists.

```lisp
(cadr ⟨arg⟩) = (car (cdr ⟨arg⟩))
```

- List operations

Scheme includes a primitive predicate null?, which tests whether its argument is the empty list.

Exercise 2.20:
dotted-tail notation
In a procedure definition, a parameter list that has a dot before the last parameter name indicates that, when the procedure is called, the initial parameters (if any) will have as values the initial arguments, as usual, but the final parameter’s value will be a list of any remaining arguments.

- Mapping over lists

### 2.2.2 Hierarchical Structures

trees
```lisp
pair?
null?
even?
odd?
nil
prime?
eq?

(eq? 1 '1);true
(eq? 1 '2);false
(equal? 1 '1);true
(equal? 1 '2);false
```
- Mapping over trees

### 2.2.3 Sequences as Conventional Interfaces
- Sequence Operations
- Nested Mappings
  For this, we generate (list nil), which is a sequence with one item, namely the set with no elements. 

### 2.2.4 Example: A Picture Language
- The picture language

painter
wave - a primitive painter
rogers
beside operation takes two painters and produces a new, compound painter

SICP上使用的两个painter（wave和rogers）没有在这个包里提供，取而代之是diagonal-shading和einstein。

The beside or below of two painters is itself a painter;

As with building up list structure using cons, the closure of our data under the means of combination is crucial to the ability to create complex structures while using only a few operations.

- Higher-order operations

- Frames
A frame can be described by three vectors—an origin vector and two edge vectors. 
The origin vector specifies the offset of the frame’s origin from some absolute origin in the plane, and the edge vectors specify the offsets of the frame’s cor- ners from its origin. 

frame coordinate map

- Painters
Representing painters as procedures erects a powerful abstraction barrier in the picture language.

- Transforming and combining painters
The transformed painter, when called on a frame, transforms the frame and calls the original painter on the transformed frame. 

- Levels of language for robust design

critical ideas
  - abstraction with procedures and data
  - `stratified design`

## 2.3 Symbolic Data

### 2.3.1 Quotation

  The single quote is different from the double quote we have been using to enclose character strings to be printed. Whereas the single quote can be used to denote lists or symbols, the double quote is used only with character strings. In this book, the only use for character strings is as items to be printed.

  our use of the quotation mark violates the general rule that all compound expressions in our language should be delimited by parentheses and look like lists.

In keeping with this, we can obtain the empty list by evaluating '(), and thus dispense with the variable nil.

```lisp
eq?
memq

(memq 'apple '(x  (apple sauce) y apple pear))
> (apple pear)      ; this (apple sauce) is a list
```

```lisp
(cdr '((x1 x2) (y1 y2)))   ; ((y1 y2))
(cadr '((x1 x2) (y1 y2)))   ; (y1 y2)
```

In practice, programmers use equal? to compare lists that contain numbers as well as symbols. Numbers are not considered to be symbols. The question of whether two numerically equal numbers (as tested by =) are also eq? is highly implementation- dependent. A better definition of equal? (such as the one that comes as a primitive in Scheme) would also stipulate that if a and b are both numbers, then a and b are equal? if they are numerically equal.

```lisp
(number? '1) ; true
(number? 1)  ; true
(+ '1 2)   ; 3
```

### 2.3.2 Example: Symbolic Differentiation

- The differentiation program with abstract data
- Representing algebraic expressions

### 2.3.3 Example: Representing Sets

Informally, a set is simply a collection of distinct objects. 

- Sets as unordered lists
- Sets as ordered lists
- Sets as binary trees
  entry left right
- Sets and information retrieval
  
### 2.3.4 Example: Huffman Encoding Trees
fixed-length codes
variable-length codes: Morse code
Huffman encoding method

- Generating Huffman trees
- The decoding procedure
- Sets of weighted elements

## 2.4 Multiple Representations for Abstract Data

These data-abstraction barriers are powerful tools for controlling complexity.

complex numbers may be represented in two almost equivalent ways: in rectangular form (real and imaginary parts) and in polar form (magnitude and angle).

generic procedures
type tags
data-directed

### 2.4.1 Representations for Complex Numbers
In actual computational systems, rectangular form is preferable to polar form most of the time because of roundoff errors in conversion between rectangular and polar form. 

### 2.4.2 Tagged data

### 2.4.3 Data-Directed Programming and Additivity
The general strategy of checking the type of a datum and calling an appropriate procedure is called dispatching on type.

operation-and-type table

- (put ⟨op ⟩ ⟨type ⟩ ⟨item ⟩) installs the ⟨item ⟩ in the table, indexed by the ⟨op ⟩ and the ⟨type ⟩.
- (get ⟨op ⟩ ⟨type ⟩) looks up the ⟨op ⟩, ⟨type ⟩ entry in the table and returns the item found there. If no item is found, get returns false.

- data-directed programming
Data-directed programming is the technique of designing programs to work with such a table directly.

- Message passing
The key idea of data-directed programming is to handle generic opera- tions in programs by dealing explicitly with operation-and-type tables

instead of using “intelligent operations” that dispatch on data types, to work with “intelligent data objects” that dispatch on operation names.

## 2.5 Systems with Generic Operations
Now we will see how to use this same idea not only to define operations that are generic over different representations but also to define operations that are generic over different kinds of arguments.

### 2.5.1 Generic Arithmetic Operations

### 2.5.2 Combining Data of Different Types

- Coercion
  coercion table

- Hierarchies of types
  tower
  The particular hierarchy we have here is of a very simple kind, in which each type has at most one supertype and at most one subtype. Such a structure, called a tower
- Inadequacies of hierarchies


### 2.5.3 Example: Symbolic Algebra

- Arithmetic on polynomials
- Representing term lists

A polynomial is said to be dense if it has nonzero coefficients in terms of most orders. If it has many zero terms it is said to be sparse.

- Hierarchies of types in symbolic algebra
- Extended exercise: Rational functions

# chapter 3 Modularity, Objects, and State
The first organizational strategy concentrates on objects, viewing a large system as a collection of distinct objects whose behaviors may change over time. An alternative organizational strategy concentrates on the streams of information that flow in the system, much as an electrical engineer views a signal-processing system.

## 3.1 Assignment and Local State

### 3.1.1 Local State Variables

```lisp
(set! ⟨name⟩ ⟨new-value⟩)

(begin ⟨exp1⟩ ⟨exp2⟩ . . . ⟨expk⟩)
```
the expressions ⟨exp1⟩ through ⟨expk⟩ to be evaluated in sequence and the value of the final expression ⟨expk ⟩ to be returned as the value of the entire begin form.

an additional procedure dispatch that takes a “message” as input and returns one of the two local procedures.

message-passing

### 3.1.2 The Benefits of Introducing Assignment

Monte Carlo simulation

by introducing assignment and the technique of hiding state in local variables, we are able to structure systems in a more modular fashion than if all state had to be manipulated explicitly, by passing additional parameters.

### 3.1.3 The Costs of Introducing Assignment

functional programming

substitution is based ultimately on the notion that the symbols in our language are essentially names for values.But as soon as we introduce set! and the idea that the value of a variable can change, a variable can no longer be simply a name. Now a variable somehow refers to a place where a value can be stored, and the value stored at this place can change. 

- Sameness and change

A language that supports the concept that “equals can be substituted for equals” in an expression without changing the value of the expression is said to be referentially transparent.

- Pitfalls of imperative programming

In contrast to functional programming, programming that makes ex- tensive use of assignment is known as imperative programming.

## 3.2 The Environment Model of Evaluation

An environment is a sequence of frames. Each frame is a table (possibly empty) of bindings, which associate variable names with their corresponding values. (A single frame may contain at most one binding for any variable.) Each frame also has a pointer to its enclosing environment, unless, for the purposes of discussion, the frame is considered to be global. The value of a variable with respect to an environment is the value given by the binding of the variable in the first frame in the environment that contains a binding for that variable. If no frame in the sequence specifies a binding for the variable, then the variable is said to be unbound in the environment.

### 3.2.1 The Rules for Evaluation

In general, define creates definitions by adding bindings to frames.

The environment model of procedure application can be summa- rized by two rules:
- A procedure object is applied to a set of arguments by construct- ing a frame, binding the formal parameters of the procedure to the arguments of the call, and then evaluating the body of the proce- dure in the context of the new environment constructed. e new frame has as its enclosing environment the environment part of the procedure object being applied.
- A procedure is created by evaluating a λ-expression relative to a given environment. The resulting procedure object is a pair con- sisting of the text of the λ-expression and a pointer to the envi- ronment in which the procedure was created.

### 3.2.2 Applying Simple Procedures

### 3.2.3Frames as the Repository of Local State

### 3.2.4 Internal Definitions

The environment model thus explains the two key properties that make local procedure definitions a useful technique for modularizing programs:
- The names of the local procedures do not interfere with names external to the enclosing procedure, because the local procedure names will be bound in the frame that the procedure creates when it is run, rather than being bound in the global environment.
- The local procedures can access the arguments of the enclosing procedure, simply by using parameter names as free variables. This is because the body of the local procedure is evaluated in an environment that is subordinate to the evaluation environment for the enclosing procedure.

## 3.3 Modeling with Mutable Data

In order to model compound objects with changing state, we will design data abstractions to include, in addition to selectors and constructors, operations called mutators, which modify data objects. 

### 3.3.1 Mutable List Structure

- Sharing and identity

More generally, (eq? x y) tests whether x and y are the same object (that is, whether x and y are equal as pointers).

- Mutation is just assignment

### 3.3.2 Representing Qeues

a queue is sometimes called a FIFO (first in, first out) buffer

### 3.3.3 Representing Tables

- Two-dimensional tables
- Creating local tables

### 3.3.4 A simulator for Digital Circuits

event-driven simulation

inverter
and-gate
or-gate

- Primitive function boxes
- Representing wires

These procedures are simply syntactic sugar that allow us to use ordinary procedural syntax to access the local procedures of objects. It is striking that we can interchange the role of “procedures” and “data” in such a simple way. For example, if we write (wire 'get-signal) we think of wire as a procedure that is called with the message get-signal as input. Alternatively, writing (get-signal wire) encourages us to think of wire as a data object that is the input to a procedure get-signal. The truth of the matter is that, in a language in which we can deal with procedures as objects, there is no fundamental difference between “procedures” and “data,” and we can choose our syntactic sugar to allow us to program in whatever style we choose.

- The agenda
- A sample simulation
- Implementing the agenda

### 3.3.5 Propagation of Constraints

- Using the constraint system
- Implementing the constraint system
- Representing connectors

## 3.4 Concurrency: Time Is of the Essence

### 3.4.1 The Nature of Time in Concurrent Systems

- Correct behavior of concurrent programs

### 3.4.2 Mechanisms for Controlling Concurrency

- Serializing access to shared state
- Serializers in Scheme
  ```lisp
  (parallel-execute ⟨p1⟩ ⟨p2⟩ . . . ⟨pk⟩)
  ```
- Complexity of using multiple shared resources

- Implementing serializers
  The term “mutex” is an abbreviation for mutual exclusion.
  mutex 互斥元
- Deadlock
- Concurrency, time, and communication

## 3.5 Streams

### 3.5.1 Streams Are Delayed Lists

the-empty-stream, which cannot be the result of any cons-stream operation, and which can be identified with the predicate stream-null?

With ordinary lists, both the car and the cdr are evaluated at construction time. With streams, the cdr is evaluated at selection time.

- The stream implementation in action
- Implementing delay and force
  
delay must package an expression so that it can be evaluated later on demand, and we can ac- complish this simply by treating the expression as the body of a proce- dure. 
delay can be a special form such that
`(delay ⟨exp⟩)`
is syntactic sugar for
`(lambda () ⟨exp⟩)`
force simply calls the procedure (of no arguments) produced by delay, so we can implement force as a procedure:
`(define (force delayed-object) (delayed-object))`


### 3.5.2 Infinite Streams

sieve of Eratosthenes 厄拉多塞筛法
To sieve a stream S, form a stream whose first element is the first element of S and the rest of which is obtained by filtering all multiples of the first element of S out of the rest of S and sieving the result.

- Defining streams implicitly

### 3.5.3 Exploiting the Stream Paradigm

- Formulating iterations as stream processes
  
  sequence accelerator
  tableau

  Even better, we can accelerate the accelerated sequence, and recursively accelerate that, and so on. Namely, we create a stream of streams (a structure we’ll call a tableau) in which each stream is the transform of the preceding one

- Infinite streams of pairs
- Streams as signals

### 3.5.4 Streams and Delayed Evaluation

In general, delay is crucial for using streams to model signal-processing systems that contain loops.

delayed argument

- Normal-order evaluation

### 3.5.5 Modularity of Functional Programs and Modularity of Objects

Stream models can provide an equivalent modularity without the use of assignment. 

- A functional-programming view of time
Indeed, because of the presence of delay there may be little relation between simulated time in the model and the order of events during the evaluation.

# chapter 4 Metalinguistic Abstraction 元语言抽象

the trick is to learn the trick

evaluator 求值器 interpreter 解释器

The evaluator, which determines the meaning of expressions in a programming language, is just another program.

## 4.1 The Metacircular Evaluator 元循环求值器

An evaluator that is written in the same language that it evaluates is said to be metacircular.

### 4.1.1 The Core of the Evaluator

The evaluation process can be described as the interplay between two
procedures: eval and apply.
- Eval
eval takes as arguments an expression and an environment.
- Apply
- Procedure arguments
- Conditionals
- Sequences
- Assignments and definitions

### 4.1.2 Representing Expressions

derived expressions 派生表达式

### 4.1.3 Evaluator Data Structures

### 4.1.4 Running the Evaluator as a Program

### 4.1.5 Data as Programs

### 4.1.6 Internal Definitions

### 4.1.7 Separating Syntactic Analysis from Execution

## 4.2 Variations on a Scheme — Lazy Evaluation

Indeed, new languages are often invented by first writing an evaluator that embeds the new language within an exist- ing high-level language. 

### 4.2.1 Normal Order and Applicative Order

Scheme is an applicative-order language, namely, that all the arguments to Scheme procedures are evaluated when the procedure is applied. 

In contrast, normal-order languages delay evaluation of pro- cedure arguments until the actual argument values are needed. 

Delaying evaluation of procedure arguments until the last possible moment (e.g., until they are required by a primitive operation) is called lazy evaluation.

If the body of a procedure is entered before an argument has been evaluated we say that the procedure is non-strict in that argument.

A striking example of a procedure that can usefully be made non-strict is cons (or, in general, almost any constructor for data structures).

### 4.2.2 An Interpreter with Lazy Evaluation

The process of evaluating the expression in a thunk is called forc- ing.

- Representing thunks

### 4.2.3 Streams as Lazy Lists

## 4.3 Variations on a Scheme — Nondeterministic Computing

### 4.3.1 Amb and Search

- Driver loop

### 4.3.2 Examples of Nondeterministic Programs

- Parsing natural language

### 4.3.3 Implementing the amb Evaluator

- Execution procedures and continuations

## 4.4 Logic Programming

### 4.4.1 Deductive Information Retrieval

- A sample data base
- Simple queries
- Compound queries
- Rules
- Logic as programs

### 4.4.2 How the query System Works

- Pattern matching
- Streams of frames
- Compound queries
- Unification

### 4.4.3 Is Logic Programming Mathematical Logic?

- Infinite loops
- Problems with not

### 4.4.4 Implementing the query System

# chapter 5 Computing with Register Machines

Such a computer, or register machine, sequentially executes instructions that manipulate the contents of a fixed set of storage elements called registers.

## 5.1 Designing Register Machines

To design a register machine, we must design its data paths (registers and operations) and the controller that sequences these operations. 

### 5.1.1 A Language for Describing Register Machines

- Actions

 We will represent an action in a data-path diagram just as we represent an operation that computes a value—as a trapezoid that con- tains the name of the action.

### 5.1.2 Abstraction in Machine Design

### 5.1.3 Subroutines
