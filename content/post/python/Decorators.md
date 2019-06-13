---
title: "Decorators"
date: 2019-06-02T16:35:27+08:00
draft: true
---

# 装饰器 Decorators

## [理解 Python 装饰器看这一篇就够了](https://foofish.net/python-decorator.html)

Python 中的函数可以像普通变量一样当做参数传递给另外一个函数

装饰器本质上是一个 Python 函数或类，它可以让其他函数或类在不需要做任何代码修改的前提下增加额外功能，装饰器的返回值也是一个函数/类对象。它经常用于有切面需求的场景，比如：插入日志、性能测试、事务处理、缓存、权限校验等场景，装饰器是解决这类问题的绝佳设计。有了装饰器，我们就可以抽离出大量与函数功能本身无关的雷同代码到装饰器中并继续重用。概括的讲，装饰器的作用就是为已经存在的对象添加额外的功能。

函数进入和退出时 ，被称为一个横切面，这种编程方式被称为面向切面的编程。

## [如何正确理解@classmethod与@staticmethod](https://foofish.net/different_bettween_classmethod_and_staticmethod.html)

Python面向对象编程中，类中定义的方法可以是 @classmethod 装饰的类方法，也可以是 @staticmethod 装饰的静态方法，用的最多的还是不带装饰器的实例方法

```python
class A(object):
    def m1(self, n):
        print("self:", self)

    @classmethod
    def m2(cls, n):
        print("cls:", cls)

    @staticmethod
    def m3(n):
        pass

a = A()
a.m1(1) # self: <__main__.A object at 0x000001E596E41A90>
A.m2(1) # cls: <class '__main__.A'>
A.m3(1)

```
### 实例方法
```python
print(A.m1)
# A.m1在py2中显示为<unbound method A.m1>
<function A.m1 at 0x000002BF7FF9A488>

print(a.m1)
<bound method A.m1 of <__main__.A object at 0x000002BF7FFA2BE0>>

```
A.m1是一个还没有绑定实例对象的方法，对于未绑定方法，调用 A.m1 时必须显示地传入一个实例对象进去，而 a.m1是已经绑定了实例的方法，python隐式地把对象传递给了self参数，所以不再手动传递参数，这是调用实例方法的过程。

我在类中一共定义了3个方法，m1 是实例方法，第一个参数必须是 self（约定俗成的）。m2 是类方法，第一个参数必须是cls（同样是约定俗成），m3 是静态方法，参数根据业务需求定，可有可无。

```python
A.m1(a, 1)
# 等价  
a.m1(1)
```
如果未绑定的方法 A.m1 不传实例对象给 self 时，就会报参数缺失错误，在 py3 与 py2 中，两者报的错误不一致，python2 要求第一个参数self是实例对象，而python3中可以是任意对象。

```python
A.m1(1)
TypeError: m1() missing 1 required positional argument: 'n'
```
### 类方法

```python
print(A.m2)
<bound method A.m2 of <class '__main__.A'>>

print(a.m2)
<bound method A.m2 of <class '__main__.A'>>

```

m2是类方法，不管是 A.m2 还是 a.m2，都是已经自动绑定了类对象A的方法，对于后者，因为python可以通过实例对象a找到它所属的类是A，找到A之后自动绑定到 cls。

```python
A.m2(1) 
 # 等价
a.m2(1) 
```

这使得我们可以在实例方法中通过使用 self.m2()这种方式来调用类方法和静态方法。

```python
def m1(self, n):
    print("self:", self)
    self.m2(n)
```

### 静态方法

```python
print(A.m3)
<function A.m3 at 0x000002BF7FF9A840>

print(a.m3)
<function A.m3 at 0x000002BF7FF9A840>

```
m3是类里面的一个静态方法，跟普通函数没什么区别，与类和实例都没有所谓的绑定关系，它只不过是碰巧存在类中的一个函数而已。不论是通过类还是实例都可以引用该方法。

```python
 A.m3(1) 
 # 等价
 a.m3(1)
```
如果在方法中不需要访问任何实例方法和属性，纯粹地通过传入参数并返回数据的功能性方法，那么它就适合用静态方法来定义，它节省了实例化对象的开销成本，往往这种方法放在类外面的模块层作为一个函数存在也是没问题的，而放在类中，仅为这个类服务。例如下面是微信公众号开发中验证微信签名的一个例子，它没有引用任何类或者实例相关的属性和方法。


# 闭包

## [一步一步教你认识Python闭包](https://foofish.net/python-closure.html)

在计算机科学中，闭包（Closure）是词法闭包（Lexical Closure）的简称，是引用了自由变量的函数。这个被引用的自由变量将和这个函数一同存在，即使已经离开了创造它的环境也不例外。所以，有另一种说法认为闭包是由函数和与其相关的引用环境组合而成的实体。

```python
def print_msg():
    # print_msg 是外围函数
    msg = "zen of python"
    def printer():
        # printer 是嵌套函数
        print(msg)
    return printer

another = print_msg()
# 输出 zen of python
another()
```

```python
def adder(x):
    def wrapper(y):
        return x + y
    return wrapper

adder5 = adder(5)
# 输出 15
adder5(10)
# 输出 11
adder5(6)
```

所有函数都有一个 __closure__属性，如果这个函数是一个闭包的话，那么它返回的是一个由 cell 对象 组成的元组对象。cell 对象的cell_contents 属性就是闭包中的自由变量。

```python
>>> adder.__closure__
>>> adder5.__closure__
(<cell at 0x103075910: int object at 0x7fd251604518>,)
>>> adder5.__closure__[0].cell_contents
5
```

局部变量脱离函数之后，还可以在函数之外被访问的原因的，因为它存储在了闭包的 cell_contents中了。

# 多线程

## [为什么有人说 Python 多线程是鸡肋？](https://foofish.net/thread.html)

是什么原因导致多线程不快反慢的呢？

原因就在于 GIL ，在 Cpython 解释器（Python语言的主流解释器）中，有一把全局解释锁（Global Interpreter Lock），在解释器解释执行 Python 代码时，先要得到这把锁，意味着，任何时候只可能有一个线程在执行代码，其它线程要想获得 CPU 执行代码指令，就必须先获得这把锁，如果锁被其它线程占用了，那么该线程就只能等待，直到占有该锁的线程释放锁才有执行代码指令的可能。

因此，这也就是为什么两个线程一起执行反而更加慢的原因，因为同一时刻，只有一个线程在运行，其它线程只能等待，即使是多核CPU，也没办法让多个线程「并行」地同时执行代码，只能是交替执行，因为多线程涉及到上线文切换、锁机制处理（获取锁，释放锁等），所以，多线程执行不快反慢。

