---
title: "Build VTK with QT on mac"
date: 2019-05-12T10:15:48+08:00
draft: true
---
refer to <https://blog.csdn.net/lijiang1991/article/details/51218705>
环境： 
- Mac OSX 10.13
- Qt 5.12
- QtCreator 4.8
- cmake version 3.14

1. Download source package from <https://vtk.org/download/>, here we download VTK-8.2.0.zip.
2. 创建build文件夹，存放编译文件
3. 通过cmakeGUI工具进行配置，选择你的VTK目录及其build目录，按左下角的configure配置，选择生成Unix Makefiles.
4. cmake一般需要多次，configure，红色警告，修改配置，再次configure，直到无红色警告再Generate。
5. 主要配置：
   | -- | -- |
   | BUILD_SHARED_LIBS | ON |
   | BUILD_EXAMPLES | ON |
   | VTK_Group_QT | ON |
   | Qt5_DIR | /Users/tom/Qt/5.13.0/clang_64/lib/cmake/Qt5|
6. Terminal 切换到build目录下，执行`make -j8`，其中-j8 为多线程执行命令，加速编译过程
7. 最后安装 `make install -j8`，这样就安装王完成了。
8. VTK安装路径一般在/usr/local/include 和 /usr/local/lib下。


# use vtk by qt

## Error 1
refer to <https://stackoverflow.com/questions/18642155/no-override-found-for-vtkpolydatamapper>

>Error: no override found for 'vtkPolyDataMapper'.

### solution
inserting the 3 following lines at the very top of my source files, before any other preprocessor directives:
```c++
#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);   // this line to enable the interaction
```

## Error 2
refer to <https://blog.csdn.net/jiugeshao/article/details/71276111>

>ERROR: In /Users/liuhaowei/Downloads/software/VTK/VTK-8.2.0/Rendering/Core/vtkTextActor.cxx, line 113  <br />
vtkTextActor (0x7f9dacb470c0): Failed getting the TextRenderer instance!

### solution:
insert the following line.
```c++
VTK_MODULE_INIT(vtkRenderingFreeType)
```
