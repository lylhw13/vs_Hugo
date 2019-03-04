---
title: "Qt document"
date: 2019-01-23T09:15:07+08:00
draft: true
---

# [The QML Reference](http://doc.qt.io/qt-5/qmlreference.html)

# [QML Object Attributes](http://doc.qt.io/qt-5/qtqml-syntax-objectattributes.html)

This id must begin with a lower-case letter or an underscore, and cannot contain characters other than letters, numbers and underscores.

Property names must begin with a lower case letter and can only contain letters, numbers and underscores.

Properties are type safe. A property can only be assigned a value that matches the property type.



### [First Steps with QML](https://doc.qt.io/qt-5/qmlfirststeps.html#)

One of the great advantages of using QML to define a user interface is that it allows the user interface designer to define how the application should react to events with simple JavaScript expressions. In QML, we refer to those events as signals and these signals are handled by signal handlers.

### [Deploying QML Applications](https://doc.qt.io/qt-5/qtquick-deployment.html)
If application.qml does not have any graphical components, or if it is preferred to avoid QQuickView for other reasons, the QQmlEngine can be constructed directly instead.

### [QML Coding Conventions](https://doc.qt.io/qt-5/qml-codingconventions.html)

## [Overview - QML and C++ Integration](https://doc.qt.io/qt-5/qtqml-cppintegration-overview.html#defining-qml-types-from-c)

## [Model/View Programming](https://doc.qt.io/qt-5/model-view-programming.html)


# pro files

<https://doc.qt.io/qt-5/qmake-project-files.html>

<https://doc.qt.io/qt-5/qmake-variable-reference.html#installs>
Variable | Contents
-- | --
CONFIG | General project configuration options.
DESTDIR | The directory in which the executable or binary file will be placed.
FORMS | A list of UI files to be processed by the user interface compiler (uic).
HEADERS | A list of filenames of header (.h) files used when building the project.
QT | A list of Qt modules used in the project.
RESOURCES | A list of resource (.qrc) files to be included in the final project. See the The Qt Resource System for more information about these files.
SOURCES | A list of source code files to be used when building the project.
TEMPLATE | The template to use for the project. This determines whether the output of the build process will be an application, a library, or a plugin. 

<https://doc.qt.io/qt-5/qmake-language.html>

- The ! symbol is used to negate the test. 
- Nested scopes can be joined together using colons.
    - Generally, the : operator behaves like a logical AND operator, joining together a number of conditions, and requiring all of them to be true. 
    - You may also use the : operator to perform single line conditional assignments. 
- The contents of a variable can be read by prepending the variable name with `$$`.


## summary
<https://doc.qt.io/qt-5/qobject.html>
- Q_OBJECT
  
    The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system.
    This macro requires the class to be a subclass of QObject.

- Q_PROPERTY( ...)
    
    The property name and type and the READ function are required. The type can be any type supported by QVariant, or it can be a user-defined type. The other items are optional, but a WRITE function is common. The attributes default to true except USER, which defaults to false.

<https://doc.qt.io/qt-5/qqmlengine.html>

- qmlRegisterType

    Note that it's perfectly reasonable for a library to register types to older versions than the actual version of the library. Indeed, it is normal for the new library to allow QML written to previous versions to continue to work, even if more advanced versions of some of its types are available.

<https://doc.qt.io/qt-5/qmlapplications.html>

- QML
    QML is a user interface specification and programming language. 
- Qt Quick
    Qt Quick is the standard library of types and functionality for QML.

<https://doc.qt.io/qt-5/qtquickcontrols-index.html>
- Qt Quick Controls 2 
    Qt Quick Controls 2 provides a set of controls that can be used to build complete interfaces in Qt Quick.

## [The Meta-Object System](https://doc.qt.io/qt-5/metaobjects.html)
To provid the signals and slots mechanism for communication between objects is the main reason for introducing the system.
Therefore, we strongly recommend that all subclasses of QObject use the Q_OBJECT macro regardless of whether or not they actually use signals, slots, and properties. 