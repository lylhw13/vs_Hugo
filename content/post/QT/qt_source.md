QApplication object. This object manages application-wide resources and is necessary to run any Qt program that uses Qt Widgets. It constructs an application object with argc command line arguments run in argv. 

Widgets are not visible by default; the function show() makes the widget visible.

exec() make QApplication enter its event loop. When a Qt application is running, events are generated and sent to the widgets of the application. Examples of events are mouse presses and key strokes.

```c++
int QCoreApplication::exec()
{
    threadData->quitNow = false;
    QEventLoop eventLoop;
    self->d_func()->in_exec = true;
    self->d_func()->aboutToQuitEmitted = false;
    int returnCode = eventLoop.exec();
    threadData->quitNow = false;

    if (self)
        self->d_func()->execCleanup();

    return returnCode;
}
```

Qt 的元对象系统（meta-object system）提供如下优点：
- 基于信号槽的对象间的通信机制（the signals and slots mechanism for inter-object communication）
- 运行时类型信息（run-time type information）
- 动态特性系统（the dynamic property system）

The meta-object system is based on three things:
- QObject 作为基类
- Q_OBJECT 作为类私有区域的第一条宏
- 使用 Meta-Object Compiler (moc) 编译器

The moc tool reads a C++ source file. If it finds one or more class declarations that contain the Q_OBJECT macro, it produces another C++ source file which contains the meta-object code for each of those classes. This generated source file is either #include'd into the class's source file or, more usually, compiled and linked with the class's implementation.

信号槽 
- 类型安全（参数相等或者 槽的参数的个数可以小于信号的参数个数，因为槽可以忽略个别参数）
- 可以一对多或者多对一

signals
- signals 由 moc 自动生成，不能在 cpp 中实现
- 返回值为void

slots
槽函数是普通的成员函数
- 普通访问遵循访问等级的约束
- 通过信号槽，不受访问等级的约束

因为需要定位连接对象，信号槽机制比回调函数慢10倍左右，但对于new 或 delete 操作还是微不足道，因此对于整体程序但效率还是可以忽略不计。
This is the overhead required to locate the connection object, to safely iterate over all connections (i.e. checking that subsequent receivers have not been destroyed during the emission), and to marshall any parameters in a generic fashion. 

```c++
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter() { m_value = 0; }

    int value() const { return m_value; }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}

Counter a, b;
QObject::connect(&a, &Counter::valueChanged,
                    &b, &Counter::setValue);
```


Q_OBJECT

When Q_OBJECT in xxx.h, after qmake, the system will generate a moc_xxx.cpp with xxx.h in it.
When Q_OBJECT in xxx.cpp, after qmake, the system will generate a xxx.moc, and `you need to add the .moc file into the .cpp file`.

A guarded pointer, QPointer<T>, behaves like a normal C++ pointer T *, except that it is automatically cleared when the referenced object is destroyed (unlike normal C++ pointers, which become "dangling pointers" in such cases). T must be a subclass of QObject.