---
title: "Pro_file"
date: 2019-06-21T11:13:15+08:00
draft: true
---

## [Specify Mac platform in qmake (QTCreater)](https://stackoverflow.com/questions/18462420/how-to-specify-mac-platform-in-qmake-qtcreator)

Detect Mac OS X this way:
```
macx {
    SOURCES += hellomac.cpp
}
```

But to make the difference with Linux you would rather like to specify
```
unix:!macx {
    SOURCES += hellolinux.cpp
}

macx: {
    SOURCES += hellomac.cpp
}
```

`mac`: it applies both on Mac OS X and iOS

`macx`: it is specific to Mac OS X.

## add macos sdk

check the Qt/5.13.0/clang_64/mkspecs/qdevice.pri
```pri
QMAKE_APPLE_DEVICE_ARCHS = x86_64
QMAKE_MAC_SDK = macosx
GCC_MACHINE_DUMP =
```

so, add `QMAKE_MAC_SDK = macosx` to the pro file.
