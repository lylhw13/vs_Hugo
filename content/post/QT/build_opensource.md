---
title: "Build_opensource"
date: 2019-05-09T10:35:23+08:00
draft: true
---

# projects
## mayo

打开 `VS2015 x86 x64 Cross Tools Command Prompt`
```sh
cd mayo_dircetory
D:\OpenCASCADE-7.3.0-vc14-64\opencascade-7.3.0\env.bat
qmake
nmake
```

# Errors 

## NMAKE : fatal error U1077: “rc”: return code“0x1” Stop.


## cmake
failed to run msbuild command
### solution
should choose the right verison of visual studio
Search MSBuild.exe
发现只有2017版的MSBuild.exe
