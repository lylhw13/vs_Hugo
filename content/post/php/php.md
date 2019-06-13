---
title: "Php"
date: 2019-05-30T21:39:30+08:00
draft: true
---

变量名称对大小写敏感

php自动确定数据类型

php global关键词用于在函数内访问全局变量。

echo 和 print 之间的差异：

- echo - 能够输出一个以上的字符串
- print - 只能输出一个字符串，并始终返回 1
提示：echo 比 print 稍快，因为它不返回任何值。

echo 是一个语言结构，有无括号均可使用：echo 或 echo()。
print 也是语言结构，有无括号均可使用：print 或 print()。

特殊的 NULL 值表示变量无值。NULL 是数据类型 NULL 唯一可能的值。

NULL 值标示变量是否为空。也用于区分空字符串与空值数据库。

可以通过把值设置为 NULL，将变量清空

# 常量
有效的常量名以字符或下划线开头（常量名称前面没有 $ 符号）。

如需设置常量，请使用 define() 函数，它使用三个参数：

1. 首个参数定义常量的名称
2. 第二个参数定义常量的值
3. 可选的第三个参数规定常量名是否对大小写不敏感。默认是 false。也就是默认对大小写敏感。

常量是自动全局的，而且可以贯穿整个脚本使用。

php / 除法，不自动取整

```php
# 串接
<?php
$a = "Hello";
$b = $a . " world!";
echo $b; // 输出 Hello world!
# 串接赋值
$x="Hello";
$x .= " world!";
echo $x; // 输出 Hello world!
?>
```

foreach 循环只适用于数组，并用于遍历数组中的每个键/值对。
```php
foreach ($array as $value) {
  code to be executed;
}
```
# 函数
注释：函数名能够以字母或下划线开头（而非数字）。

注释：函数名对大小写不敏感。

```php
function functionName() {
  被执行的代码;
}
```

# 数组

在 PHP 中，有三种数组类型：

- 索引数组 - 带有数字索引的数组
- 关联数组 - 带有指定键的数组
- 多维数组 - 包含一个或多个数组的数组

count() 函数用于返回数组的长度（元素数）
```php
#遍历关联数组
<?php
$age=array("Bill"=>"63","Steve"=>"56","Elon"=>"47");

foreach($age as $x=>$x_value) {
  echo "Key=" . $x . ", Value=" . $x_value;
  echo "<br>";
}
?>

```

# 超全局变量
超全局变量在 PHP 4.1.0 中引入，是在全部作用域中始终可用的内置变量。

$_GET 是通过 URL 参数传递到当前脚本的变量数组。

$_POST 是通过 HTTP POST 传递到当前脚本的变量数组。
## GET
通过 GET 方法从表单发送的信息对任何人都是可见的（所有变量名和值都显示在 URL 中）。GET 对所发送信息的数量也有限制。限制在大于 2000 个字符。不过，由于变量显示在 URL 中，把页面添加到书签中也更为方便。

GET 可用于发送非敏感的数据。

注释：绝不能使用 GET 来发送密码或其他敏感信息！

## POST

通过 POST 方法从表单发送的信息对其他人是不可见的（所有名称/值会被嵌入 HTTP 请求的主体中），并且对所发送信息的数量也无限制。

此外 POST 支持高阶功能，比如在向服务器上传文件时进行 multi-part 二进制输入。

不过，由于变量未显示在 URL 中，也就无法将页面添加到书签。

提示：开发者偏爱 POST 来发送表单数据。

# 表单元素
什么是 $_SERVER["PHP_SELF"] 变量？
$_SERVER["PHP_SELF"] 是一种超全局变量，它返回当前执行脚本的文件名。

因此，$_SERVER["PHP_SELF"] 将表单数据发送到页面本身，而不是跳转到另一张页面。这样，用户就能够在表单页面获得错误提示信息。

什么是 htmlspecialchars() 函数？
htmlspecialchars() 函数把特殊字符转换为 HTML 实体。这意味着 < 和 > 之类的 HTML 字符会被替换为 &lt; 和 &gt; 。这样可防止攻击者通过在表单中注入 HTML 或 JavaScript 代码（跨站点脚本攻击）对代码进行利用。

在用户提交该表单时，我们还要做两件事：

1. （通过 PHP trim() 函数）去除用户输入数据中不必要的字符（多余的空格、制表符、换行）
2. （通过 PHP stripslashes() 函数）删除用户输入数据中的反斜杠（\）


include 和 require 语句是相同的，除了错误处理方面：

- require 会生成致命错误（E_COMPILE_ERROR）并停止脚本
- include 只生成警告（E_WARNING），并且脚本会继续


AJAX = Asynchronous JavaScript and XML
CSS = Cascading Style Sheets
HTML = Hyper Text Markup Language
PHP = PHP Hypertext Preprocessor
SQL = Structured Query Language
SVG = Scalable Vector Graphics
XML = EXtensible Markup Language

```php
# setcookie() 函数必须位于 <html> 标签之前。
setcookie(name, value, expire, path, domain);
```

Session 的工作机制是：为每个访问者创建一个唯一的 id (UID)，并基于这个 UID 来存储变量。UID 存储在 cookie 中，亦或通过 URL 进行传导。