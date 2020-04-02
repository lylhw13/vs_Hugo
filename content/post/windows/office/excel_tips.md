---
title: "Excel_tips"
date: 2019-07-16T15:51:10+08:00
draft: true
---

# Excel some sentence
```excel
=MOD(ROW(),2)=0
=AND(MOD(ROW(),2)=1, ROW()>2)
=TEXT(C1/D1, "0.00%")
```

# Some operations

## 将颜色应用于交替行或列
Refer to [将颜色应用于交替行或列](https://support.office.com/zh-cn/article/-%E5%B0%86%E9%A2%9C%E8%89%B2%E5%BA%94%E7%94%A8%E4%BA%8E%E4%BA%A4%E6%9B%BF%E8%A1%8C%E6%88%96%E5%88%97-30002ce0-7a1c-4d70-a70c-4b6232f09f5e) 和 [Apply color to alternate rows or columns](https://support.office.com/en-us/article/apply-color-to-alternate-rows-or-columns-30002ce0-7a1c-4d70-a70c-4b6232f09f5e?ui=en-US&rs=en-US&ad=US)

## Add trending line
选择图表上的任意一个数据点，右击，会出现添加趋势线的选择。

## Array formulas 数组公式
Create array formulas, often called `Ctrl+Shift+Enter` or CSE formulas, to perform calculations that generate single or multiple results. 

An array formula is a formula that can perform multiple calculations on one or more items in an array. You can think of an array as a row or column of values, or a combination of rows and columns of values. Array formulas can return either multiple results, or a single result.

下面这个需要同时按 `Ctrl+Shift+Enter` , 然后自动在公式外添加“{}”
```excel
=SUM(ABS(C1:C20))
```
