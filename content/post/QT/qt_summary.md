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

Each QML component is instantiated in a QQmlContext. QQmlContext's are essential for passing data to QML components. In QML, contexts are arranged hierarchically and this hierarchy is managed by the QQmlEngine.

- QQmlEngine
    - QQmlApplicationEngine
- QQmlComponent
- QQmlContext
## [QQmlEngine Class](https://doc.qt.io/qt-5/qqmlengine.html)
- The QQmlEngine class provides an environment for instantiating QML components.
- Each QML component is instantiated in a QQmlContext. QQmlContext's are essential for passing data to QML components. In QML, contexts are arranged hierarchically and this hierarchy is managed by the QQmlEngine.
- Prior to creating any QML components, an application must have created a QQmlEngine to gain access to a QML context.

## [QQmlApplicationEngine Class](https://doc.qt.io/qt-5/qqmlapplicationengine.html)
- QQmlApplicationEngine provides a convenient way to load an application from a single QML file.
- This class combines a QQmlEngine and QQmlComponent to provide a convenient way to load a single QML file. It also exposes some central application functionality to QML, which a C++/QML hybrid application would normally control from C++.
- Unlike QQuickView, QQmlApplicationEngine does not automatically create a root window. If you are using visual items from Qt Quick, you will need to place them inside of a Window.

## [QQmlComponent Class](https://doc.qt.io/qt-5/qqmlcomponent.html)
- The QQmlComponent class encapsulates a QML component definition.
- Components are reusable, encapsulated QML types with well-defined interfaces.
- A QQmlComponent instance can be created from a QML file.

## [QQmlContext Class](https://doc.qt.io/qt-5/qqmlcontext.html)
- The QQmlContext class defines a context within a QML engine.
- Contexts allow data to be exposed to the QML components instantiated by the QML engine.
- Each QQmlContext contains a set of properties, distinct from its QObject properties, that allow data to be explicitly bound to a context by name. 


- QQuickWiget
- QQuickItem
- QQuickView
## [QQuickWidget Class](https://doc.qt.io/qt-5/qquickwidget.html)
- Note: QQuickWidget is an alternative to using QQuickView and QWidget::createWindowContainer(). The restrictions on stacking order do not apply, making QQuickWidget the more flexible alternative, behaving more like an ordinary widget. This comes at the expense of performance. Unlike QQuickWindow and QQuickView, QQuickWidget involves rendering into OpenGL framebuffer objects. This will naturally carry a minor performance hit.
- Note: Using QQuickWidget disables the threaded render loop on all platforms. This means that some of the benefits of threaded rendering, for example Animator classes and vsync driven animations, will not be available.
- Note: Avoid calling winId() on a QQuickWidget. This function triggers the creation of a native window, resulting in reduced performance and possibly rendering glitches. The entire purpose of QQuickWidget is to render Quick scenes without a separate native window, hence making it a native widget should always be avoided. 


- [Positioning with Anchors](https://doc.qt.io/qt-5/qtquick-positioning-anchors.html)
- Qt Quick Layouts Overview

## commands

refer to [Prototyping with qmlscene](https://doc.qt.io/qt-5.9/qtquick-qmlscene.html)
```sh
qmlscene myqmlfile.qml
```
