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

# [C++/QML: ListView is not updated on dataChanged signal from QAbstractListModel](https://stackoverflow.com/questions/38630750/c-qml-listview-is-not-updated-on-datachanged-signal-from-qabstractlistmodel)
You mustn't declare the dataChanged() signal in your class, because you want to emit the signal AbstractItemModel::dataChanged(). If you re-declare it you add a comleptely new and different Signal that is not connected anywhere. If you remove the declaration in acdata.h everything should work fine.
# QSqlQuery::value: not positioned on a valid record
You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
refering to <https://stackoverflow.com/questions/9000123/qsqlquery-not-positioned-on-a-valid-record>

# 
>QQuickView does not support using windows as a root item. 
>If you wish to create your root window from QML, consider using QQmlApplicationEngine instead. 
- Solution 
  Unlike QQuickView, QQmlApplicationEngine does not automatically create a root window. If you are using visual items from Qt Quick, you will need to place them inside of a Window.
  所以，如果qml的root type 是Window的话，应该用 QQmlApplicationEngine.


# 
> symbol(s) not found for architecture x86_64
> linker command failed with exit code 1 (use -v to see invocation)

- Sloution
    右键点击选择Show Output查看详细信息
    最后原因为声明了slot，但是却没有为slot添加定义

# LNK1158 Qt Cannot run rc.exe

solution: 将rc.exe 的路径添加到系统或者Qt的path路径里面去。