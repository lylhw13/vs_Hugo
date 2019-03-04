---
title: "Qt summary"
date: 2018-07-17T15:33:08+08:00
draft: true
tags: ["QT", "C++"]
categories: ["C++"]
---

# QT summary

QVector doesn't have range-construction.

更全面的分析如下<https://marcmutz.wordpress.com/effective-qt/containers/>

## snippets
    ```c++
    #include <QtWidgets/QApplication>
    #include <QtGui/QGuiApplication>
    ```
`QCoreApplication` is the base class, `QGuiApplication` extends the base class with functionality related to handling windows and GUI stuff (non-widget related, e.g. OpenGL or QtQuick), `QApplication` extends QGuiApplication with functionality related to handling widgets.
