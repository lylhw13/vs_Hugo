---
title: "一些 markdown 语法"
date: 2018-09-10T15:31:16+08:00
draft: false
tags: ["Markdown"]
categories: ["Markdown"]
---


<https://markdown-zh.readthedocs.io/en/latest/blockelements/>

Markdown 中可以简便地只在每一个需要强制换行的段落的首行前面加上一个 > 

<!-- strong -->
- **This text** is strong
- __This text__ is strong

<!-- italic -->
- *This text* is italic
- _This text_ is italic

===test===

<!-- delete -->
~~This text~~ is delete

<!-- Horizontal Rule-->

---
___

<!-- Links -->
[Traversy Media](http://www.traversymedia.com)

[Traversy Media](http://www.traversymedia.com "Traversy Media") <!-- change the hint-->

<!-- Images -->
![Markdown Logo](https://markdown-here.com/img/icon256.png)

<!-- Task List -->
* [x] Task 1
* [x] Task 2
* [ ] Task 3
  
<!-- Note -->
[comment]: <> (This is a comment, it will not be included)
[comment]: <> (in  the output file unless you use it in)
[comment]: <> (a reference style link.)
[//]: <> (This is also a comment.)
[//]: # (This may be the most platform independent comment)
<!-- comment here -->
<!--
your comment goes here
and here
-->

<!-- 上下标 -->

- H<sub>2</sub>O 
- m<sup>2</sup>


## 公式
分为两种排版：
- 行内公式：用\ 或者 $ 包裹公式
- 独立公式：用 \$\$ 包裹公式。


\displaystyle - Used to over-ride automatic style rules and force display style.

$${\displaystyle {\hat {\boldsymbol {\beta }}}=(\mathbf {X} ^{\mathsf {T}}\mathbf {X} )^{-1}\mathbf {X} ^{\mathsf {T}}\mathbf {y}}$$

