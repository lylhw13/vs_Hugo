---
title: "Qt error"
date: 2019-01-22T16:26:20+08:00
draft: true
---

# ChartView - "legend" does not have members. (M17)
solve by refering to this page: [QtCharts plugins.qmltype file provides a wrong namespace for QLegend](https://bugreports.qt.io/browse/QTBUG-51704)

>For 5.12.0, replace the plugins.qmltypes file in QTDIR/qml/QtCharts with attached file.

In my case, I use Destop Qt 5.12.0 MSVC2017 64bit, so I replace plugins.qmltypes in D:\Qt\Qt5.12.0\5.12.0\msvc2017_64\qml\QtCharts with attached file.

On mac, I use Desktop Qt 5.12.0 clang 64bit, so I replace plugins.qmltypes in ~/Qt/Qt5.12.0/5.12.0/clang_64/qml/QtCharts with attached file.

# Signal QQmlEngine::quit() emitted, but no receivers connected to handle it.
- Solution <https://blog.csdn.net/mary2006lucky/article/details/52230086>
    >如果使用的是Rectangle，在main.cpp中include QQmlEngine库，再加上
    `QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));`
    即可。&app也可以用qApp替代。qApp是一个宏。
- Explanation <https://doc.qt.io/qt-5/qml-qtqml-qt.html#quit-method>
    >This function causes the QQmlEngine::quit() signal to be emitted. Within the Prototyping with qmlscene, this causes the launcher application to exit; to quit a C++ application when this method is called, connect the QQmlEngine::quit() signal to the QCoreApplication::quit() slot.

