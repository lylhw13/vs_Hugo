---
title: "Qtcreater"
date: 2019-01-22T16:26:20+08:00
draft: true
---

# ChartView - "legend" does not have members. (M17)
solve by refering to this page: [QtCharts plugins.qmltype file provides a wrong namespace for QLegend](https://bugreports.qt.io/browse/QTBUG-51704)

>For 5.12.0, replace the plugins.qmltypes file in QTDIR/qml/QtCharts with attached file.

In my case, I use Destop Qt 5.12.0 MSVC2017 64bit, so I replace plugins.qmltypes in D:\Qt\Qt5.12.0\5.12.0\msvc2017_64\qml\QtCharts with attached file.
