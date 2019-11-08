---
title: "Visual_studio_2005"
date: 2019-06-18T14:22:19+08:00
draft: true
---

# Visual Studio "Find in Files" does not work
refer to <https://stackoverflow.com/questions/9207954/visual-studio-find-in-files-does-not-work>

Visual Studio-->Windows-->Reset Window Layout. 
The resizing of the visual studio made it to hide the option.

# 快捷键

格式化代码 Ctrl + k  Ctrl + f

# Error RC2168: resource too large
![resource too large](/media/pic/visual_studio/resource_too_large.png)

打开rc文件，删除其中DESIGNINGO后面的整段ifdef, 如下面的代码全部删除。
```c++
/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO 
BEGIN
    IDD_LIGHT_OPTION, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 231
        TOPMARGIN, 7
        BOTTOMMARGIN, 323
    END

    IDD_LIGHTPROPERTY, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 183
        TOPMARGIN, 7
        BOTTOMMARGIN, 160
    END
    ...
    ...
    ...
END
#endif    // APSTUDIO_INVOKED
```