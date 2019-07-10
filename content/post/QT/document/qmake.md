---
title: "Qmake"
date: 2019-06-13T21:52:00+08:00
draft: true
---

## [Getting Started](https://doc.qt.io/qt-5/qmake-tutorial.html)

```make
win32 {
    SOURCES += hellowin.cpp
}
unix {
    SOURCES += hellounix.cpp
}

# We can stop qmake from processing by using the error() function. 

!exists( main.cpp ) {
    error( "No main.cpp file found" )
}
```

```make
win32 {
    debug {
        CONFIG += console
    }
}

# Nested scopes can be joined together using colons

win32:debug {
    CONFIG += console
}
```

## [Creating Project Files](https://doc.qt.io/qt-5/qmake-project-files.html)

`The contents of a variable can be read by prepending the variable name with $$. `

### Whitespace

Usually, whitespace separates values in variable assignments. To specify values that contain spaces, you must enclose the values in double quotes:

```qmake
    win32:INCLUDEPATH += "C:/mylibs/extra headers"
    unix:INCLUDEPATH += "/home/user/extra headers"
```

### General Configuration

The CONFIG variable specifies the options and features that the project should be configured with. You can test for the presence of certain configuration options by using the built-in CONFIG() function. 

```qmake
    CONFIG += qt debug

    CONFIG(opengl) {
        message(Building with OpenGL support.)
    } else {
        message(OpenGL support is not available.)
    }
```

### Declaring Qt Libraries

```qmake
QT += network xml
QT = network xml # This will omit the core and gui modules.
QT -= gui # Only the core module is used.
```
## [Replace Functions](https://doc.qt.io/qt-5/qmake-function-reference.html)

`You can obtain these values by prefixing a function with the $$ operator.` Replace functions can be divided into built-in functions and function libraries.

- __absolute_path(path[, base])__

    message($$absolute_path("readme.txt", "/home/johndoe/myproject"))

- __files(pattern[, recursive=false])__

    Expands the specified wildcard pattern and returns a list of filenames. If recursive is true, this function descends into subdirectories.

- __dirname(file)__

    ```qmake
    FILE = /etc/X11R6/XF86Config
    DIRNAME = $$dirname(FILE) #/etc/X11R6
    ```