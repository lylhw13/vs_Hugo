---
title: "SQL必知必会"
date: 2019-10-17T10:25:03+08:00
draft: true
---
# SQL必知必会（第四版）

# chapter 1

数据库软件应称为数据库管理系统（DBMS）。
将数据库想象为一个文件柜
存储在表中的数据是同一种类型的数据或清单。

- 数据库（database）保存有组织的数据的容器（通常是一个文件或一组文件）。
- 表（table）某种特定类型数据的结构化清单。
- 列（column）表中的一个字段。所有表都是由一个或多个列组成的。
- 行（row）表中的一个记录。
- 主键（primary key）一列（或一组列），其值能够唯一标识表中每一行。
    表中的任何列都可以作为主键，只要它满足以下条件：
    - 任意两行都不具有相同的主键值；
    - 每一行都必须具有一个主键值（主键列不允许 NULL 值）；
    - 主键列中的值不允许修改或更新；
    - 主键值不能重用（如果某行从表中删除，它的主键不能赋给以后的新行）。


SQL（发音为字母 S-Q-L或 sequel）是 Structured Query Language（结构化查询语言）的缩写。SQL是一种专门用来与数据库沟通的语言。

# chapter 2

- 关键字（keyword）作为 SQL组成部分的保留字。关键字不能用作表或列的名字。

- 多条 SQL语句必须以分号(;)分隔。
- SQL语句不区分大小写。
- 在处理SQL语句时，其中所有空格都被忽略。
- 在选择多个列时，一定要在列名之间加上逗号，但最后一个列名后不加。如果在最后一个列名后加了逗号，将出现错误。
- 检索不需要的列通常会降低检索和应用程序的性能。

- DISTINCT, 指示数据库只返回不同的值,作用于所有的列,必须直接放在列名的前面。



```mysql
select * from table_name limit 1 offset 3 -- 从偏移3条的位置选一条

-- 这是一条注释
# 这也是一条注释，很少得到支持
/* 多行注释*/
```

- 关系数据库设计理论认为，如果不明确规定排序顺序，则不应该假定检索出的数据的顺序有任何意义。

-  ORDER BY 子句的位置
在指定一条 ORDER BY 子句时，应该保证它是 SELECT 语句中最后一条子句。如果它不是最后的子句，将会出现错误消息。
通常， ORDER BY 子句中使用的列将是为显示而选择的列。但是，实际上并不一定要这样，用非检索的列排序数据是完全合法的。

```SQL
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price, prod_name;
```
```SQL
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY 2, 3;
```

```SQL
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price DESC;       --降序
```

DESC 关键字只应用到直接位于其前面的列名，如果想在多个列上进行降序排序，必须对每一列指定 DESC 关键字。
DESC 是 DESCENDING 的缩写，这两个关键字都可以使用。

```SQL
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price DESC, prod_name;
```

# chapter 4 数据过滤

搜索条件（search criteria），也称为过滤条件（filter condition）。
```SQL
SELECT prod_name, prod_price
FROM Products
WHERE prod_price = 3.49;
```

```SQL
SELECT prod_name, prod_price
FROM Products
WHERE prod_price BETWEEN 5 AND 10;
```
操 作 符 | 说 明 | 操 作 符 | 说 明
-- | -- | -- | -- |
= | 等于 | > | 大于|
<> | 不等于 | >= | 大于等于
!=  | 不等于 | !> | 不大于
< | 小于 | BETWEEN | 在指定的两个值之间
<= | 小于等于 | IS NULL | 为NULL值
!< | 不小于

- 单引号用来限定字符串。如果将值与字符串类型的列进行比较，就需要限定引号。用来与数值列进行比较的值不用引号。

- NULL 无值（no value），它与字段包含 0、空字符串或仅仅包含空格不同。

# chapter 5 高级数据过滤

- 操作符（operator）用来联结或改变 WHERE 子句中的子句的关键字，也称为逻辑操作符（logical operator）。
- AND 
- OR
```SQL
SELECT prod_name, prod_price
FROM Products
WHERE vend_id = 'DLL01' OR vend_id = ‘BRS01’;
```

```SQL
SELECT prod_name, prod_price
FROM Products
WHERE (vend_id = 'DLL01' OR vend_id = 'BRS01')
AND prod_price >= 10;
```
- IN 操作符
    - WHERE 子句中用来指定要匹配值的清单的关键字，功能与 OR 相当。
    - IN 操作符一般比一组 OR 操作符执行得更快
    - IN 的最大优点是可以包含其他 SELECT语句，能够更动态地建立WHERE子句。

```SQL
SELECT prod_name, prod_price
FROM Products
WHERE vend_id IN ( 'DLL01', 'BRS01' )
ORDER BY prod_name;
```

```SQL
SELECT prod_name
FROM Products
WHERE NOT vend_id = 'DLL01'
ORDER BY prod_name;
```

# chapter 6 通配符过滤
为在搜索子句中使用通配符，必须使用 LIKE 操作符。 
- 谓词（predicate）
操作符何时不是操作符？答案是，它作为谓词时。从技术上说， LIKE是谓词而不是操作符。

 - % 表示任何字符出现任意次数，包括0次
    - 通配符 % 看起来像是可以匹配任何东西，但有个例外，这就是 NULL。子句 WHERE prod_name LIKE '%' 不会匹配产品名称为 NULL 的行。
- _ 下划线，只匹配单个字符。
- [] 方括号，用来指定一个字符集，它必须匹配指定位置（通配符的位置）的一个字符。

```SQL
SELECT prod_id, prod_name
FROM Products
WHERE prod_name LIKE 'Fish%';
```

# chapter 7 创建计算字段

- 字段（field）
基本上与列（column）的意思相同，经常互换使用，不过数据库列一
般称为列，而术语字段通常与计算字段一起使用。

- 拼接（concatenate）
将值联结到一起（将一个值附加到另一个值）构成单个值。

此操作符可用加号（ + ）或两个竖杠（ || ）表示。在 MySQL和 MariaDB中，必须使用
特殊的函数。

```SQL
SELECT vend_name + ' (' + vend_country + ')'
FROM Vendors
ORDER BY vend_name;
```

```MySQL
SELECT Concat(vend_name, ' (', vend_country, ')')
FROM Vendors
ORDER BY vend_name;
```
许多数据库（不是所有）保存填充为列宽的文本值，而实际上你要的结果不需要这些空格。
- RTRIM() 函数去掉值右边的所有空格
```SQL
SELECT RTRIM(vend_name) + ' (' + RTRIM(vend_country) + ')'
FROM Vendors
ORDER BY vend_name;
```
## 使用别名alias
```SQL
SELECT RTRIM(vend_name) + ' (' + RTRIM(vend_country) + ')'
       AS vend_title
FROM Vendors
ORDER BY vend_name;
```
```SQL
SELECT prod_id,
       quantity,
       item_price,
       quantity*item_price AS expanded_price
FROM OrderItems
WHERE order_num = 20008;
```

# chapter 8 使用函数处理数据

```SQL
SELECT vend_name, UPPER(vend_name) AS vend_name_upcase
FROM Vendors
ORDER BY vend_name;
```
# chapter 9 汇总数据

聚集函数（aggregate function）
对某些行运行的函数，计算并返回一个值

函 数 | 说 明
-- | --
AVG() | 返回某列的平均值
COUNT() | 返回某列的行数
MAX() | 返回某列的最大值
MIN() | 返回某列的最小值
SUM() | 返回某列值之和

- AVG() 函数忽略列值为 NULL 的行。
    -AVG() 只能用来确定特定数值列的平均值，而且列名必须作为函数参数给出。为了获得多个列的平均值，必须使用多个 AVG() 函数。
```SQL
SELECT AVG(prod_price) AS avg_price
FROM Products
WHERE vend_id = 'DLL01';
```
- COUNT() 函数有两种使用方式：
    - 使用 COUNT(*) 对表中行的数目进行计数，不管表列中包含的是空值
（ NULL ）还是非空值。
    - 使用 COUNT(column) 对特定列中具有值的行进行计数，忽略 NULL 值。

- MAX() 返回指定列中的最大值。 MAX() 要求指定列名。
- MAX() MIN() SUM() 函数均忽略列值为 NULL 的行。

- ALL 参数不需要指定，因为它是默认行为。如果不指定 DISTINCT ，则假定为 ALL 。

```SQL
SELECT AVG(DISTINCT prod_price) AS avg_price
FROM Products
WHERE vend_id = 'DLL01';
```

```SQL
SELECT COUNT(*) AS num_items,
       MIN(prod_price) AS price_min,
       MAX(prod_price) AS price_max,
       AVG(prod_price) AS price_avg
FROM Products;
```

# chapter 10 分组数据

```SQL
SELECT vend_id, COUNT(*) AS num_prods
FROM Products
GROUP BY vend_id;
```

- 在使用 GROUP BY 子句前，需要知道一些重要的规定。
    - GROUP BY 子句可以包含任意数目的列，因而可以对分组进行嵌套，更细致地进行数据分组。
    - 如果在 GROUP BY 子句中嵌套了分组，数据将在最后指定的分组上进行汇总。换句话说，在建立分组时，指定的所有列都一起计算（所以不能从个别的列取回数据）。
    - GROUP BY 子句中列出的每一列都必须是检索列或有效的表达式（但不能是聚集函数）。如果在 SELECT 中使用表达式，则必须在 GROUP BY子句中指定相同的表达式。不能使用别名。
    - 大多数 SQL实现不允许 GROUP BY 列带有长度可变的数据类型（如文本或备注型字段）。
    - 除聚集计算语句外， SELECT 语句中的每一列都必须在 GROUP BY 子句中给出。
    - 如果分组列中包含具有 NULL 值的行，则 NULL 将作为一个分组返回。如果列中有多行 NULL 值，它们将分为一组。
    - GROUP BY 子句必须出现在 WHERE 子句之后， ORDER BY 子句之前。

- HAVING 支持所有 WHERE 操作符, HAVING 过滤是基于分组聚集值。
    - WHERE 在数据分组前进行过滤， HAVING 在数据分组后进行过滤。
```SQL
SELECT vend_id, COUNT(*) AS num_prods
FROM Products
WHERE prod_price >= 4
GROUP BY vend_id
HAVING COUNT(*) >= 2;
```

子 句 | 说 明 | 是否必须使用
-- | -- | --
SELECT | 要返回的列或表达式 | 是
FROM | 从中检索数据的表 | 仅在从表选择数据时使用 
WHERE | 行级过滤 | 否
GROUP BY | 分组说明 | 仅在按组计算聚集时使用
HAVING | 组级过滤 | 否
ORDER BY | 输出排序顺序 | 否

# chapter 11 子查询

在 SELECT 语句中，子查询总是从内向外处理。

```SQL
SELECT cust_id
FROM Orders
WHERE order_num IN (SELECT order_num
                    FROM OrderItems
                    WHERE prod_id = 'RGAN01');
```

- 作为子查询的 SELECT 语句只能查询单个列。企图检索多个列将返回错误。

```SQL
SELECT cust_name,
       cust_state,
       (SELECT COUNT(*)
        FROM Orders
        WHERE Orders.cust_id = Customers.cust_id) AS orders --完全限定列名
FROM Customers
ORDER BY cust_name;
```

# chapter 12 联结表

- 笛卡儿积（cartesian product）
由没有联结条件的表关系返回的结果为笛卡儿积。检索出的行的数目将是第一个表中的行数乘以第二个表中的行数。

- 叉联结
有时，返回笛卡儿积的联结，也称叉联结（cross join）。

```SQL
SELECT vend_name, prod_name, prod_price
FROM Vendors, Products
WHERE Vendors.vend_id = Products.vend_id;
```
目前为止使用的联结称为等值联结（equijoin），它基于两个表之间的相等测试。这种联结也称为内联结（inner join）。
```SQL
SELECT vend_name, prod_name, prod_price
FROM Vendors INNER JOIN Products
ON Vendors.vend_id = Products.vend_id;
```

# chapter 13 创建高级联结

- 表别名只在查询执行中使用。与列别名不一样，表别名不返回到客户端。
自联结（self-join）、自然联结（natural join）和外联结（outer join）。

- 自联结
用自联结而不用子查询自联结通常作为外部语句，用来替代从相同表中检索数据的使用子查询语句。虽然最终的结果是相同的，但许多 DBMS处理联结远比处理子查询快得多。
```SQL
SELECT c1.cust_id, c1.cust_name, c1.cust_contact
FROM Customers AS c1, Customers AS c2
WHERE c1.cust_name = c2.cust_name
AND c2.cust_contact = 'Jim Jones';
```

- 外联结
```SQL
SELECT Customers.cust_id, Orders.order_num
FROM Customers LEFT OUTER JOIN Orders
ON Customers.cust_id = Orders.cust_id;
```

```SQL
SELECT Customers.cust_id,
    COUNT(Orders.order_num) AS num_ord
FROM Customers INNER JOIN Orders
ON Customers.cust_id = Orders.cust_id
GROUP BY Customers.cust_id;
```

# chapter 14 组合查询

利用 UNION ，可给出多条SELECT 语句，将它们的结果组合成一个结果集。

- UNION 中的每个查询必须包含相同的列、表达式或聚集函数（不过，各个列不需要以相同的次序列出）。
- 列数据类型必须兼容：类型不必完全相同，但必须是 DBMS可以隐含转换的类型。

- UNION 从查询结果集中自动去除了重复的行；换句话说，它的行为与一条 SELECT 语句中使用多个 WHERE 子句条件一样。

- 使用 UNION ALL ，DBMS不取消重复的行

在用 UNION 组合查询时，只能使用一条 ORDER BY 子句，它必须位于最后一条 SELECT 语句之后。
```SQL
SELECT cust_name, cust_contact, cust_email
FROM Customers
WHERE cust_state IN ('IL','IN','MI')
UNION
SELECT cust_name, cust_contact, cust_email
FROM Customers
WHERE cust_name = 'Fun4All'
ORDER BY cust_name, cust_contact;
```

# chapter 15 插入数据

- INTO 关键字
在某些 SQL实现中，跟在 INSERT 之后的 INTO 关键字是可选的。但是，即使不一定需要，最好还是提供这个关键字，这样做将保证 SQL代码在 DBMS之间可移植。

- 总是使用列的列表
不要使用没有明确给出列的 INSERT 语句。给出列能使 SQL代码继续发挥作用，即使表结构发生了变化。

省略列
如果表的定义允许，则可以在 INSERT 操作中省略某些列。省略的列
必须满足以下某个条件。
- 该列定义为允许 NULL 值（无值或空值）。
- 在表定义中给出默认值。这表示如果不给出值，将使用默认值。



DBMS一点儿也不关心 SELECT返回的列名。它使用的是列的位置。

INSERT 通常只插入一行。要插入多行，必须执行多个 INSERT 语句。
NSERT SELECT 是个例外，它可以用一条 INSERT 插入多行，不管 SELECT语句返回多少行，都将被 INSERT 插入。

```SQL
INSERT INTO Customers(cust_id,
                        cust_contact,
                        cust_email,
                        cust_name,
                        cust_address,
                        cust_city,
                        cust_state,
                        cust_zip,
                        cust_country)
SELECT cust_id,
        cust_contact,
        cust_email,
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country
FROM CustNew;
```

SELECT INTO将数据复制到一个新表（有的 DBMS可以覆盖已经存在的表，这依赖于所使用的具体 DBMS）。
```SQL
SELECT *
INTO CustCopy
FROM Customers;
```

SELECT INTO 是试验新 SQL语句前进行表复制的很好工具。先进行复制，可在复制的数据上测试 SQL代码，而不会影响实际的数据。