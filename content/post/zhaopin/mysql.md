---
title: "Mysql"
date: 2020-06-14T12:01:18+08:00
draft: true
---

# 慢索引分析
MySQL慢查询就是在日志中记录运行比较慢的SQL语句，这个功能需要开启才能用。

在MySQL的配置文件my.cnf中写上：

long_query_time = 10
log-slow-queries = /var/lib/mysql/mysql-slow.log

long_query_time是指执行超过多久的SQL会被日志记录下来，这里是10 秒。
log-slow-queries设置把日志写在那里（例子中慢查询日志会写到文件/var/lib/mysql/mysql-slow.log中），为空的时候，系统会给慢查询日志赋予主机名，并加上slow.log。如果设置了参数log-long-format ，那么所有没有使用索引的查询也将被记录。

这是一个非常有用的日志。它对于性能的影响不大（假设所有查询都很快），并且强调了那些最需要注意的查询（丢失了索引或索引没有得到最佳应用）

mysql 索引慢分析（线上开启slowlog，提取慢查询，然后仔细分析explain 中 tye字段以及extra字段


电话号码就像地址，只是以数字的形式呈现出来，存储成varchar类型以后，方面正则匹配，格式化，和一般的字符化处理。Strings & VARCHAR.

# 数据库三大范式

1．第一范式(确保每列保持原子性)
2．第二范式(确保表中的每列都和主键相关)
3．第三范式(确保每列都和主键列直接相关,而不是间接相关)


# 缩写
MySQL 数据操作 DML（增删改查）DML（Data Manipulation Language 数据操纵语言）

SQL四种语言：DDL,DML,DCL,TCL
1.DDL（Data Definition Language）数据库定义语言statements are used to define the database structure or schema.

DDL是SQL语言的四大功能之一。
用于定义数据库的三级结构，包括外模式、概念模式、内模式及其相互之间的映像，定义数据的完整性、安全控制等约束
DDL不需要commit.
CREATE
ALTER
DROP
TRUNCATE
COMMENT
RENAME

2.DML（Data Manipulation Language）数据操纵语言statements are used for managing data within schema objects.

由DBMS提供，用于让用户或程序员使用，实现对数据库中数据的操作。
DML分成交互型DML和嵌入型DML两类。
依据语言的级别，DML又可分成过程性DML和非过程性DML两种。
需要commit.
SELECT
INSERT
UPDATE
DELETE
MERGE
CALL
EXPLAIN PLAN
LOCK TABLE

3.DCL（Data Control Language）数据库控制语言  授权，角色控制等
GRANT 授权
REVOKE 取消授权

4.TCL（Transaction Control Language）事务控制语言
SAVEPOINT 设置保存点
ROLLBACK  回滚
SET TRANSACTION

SQL主要分成四部分：
（1）数据定义。（SQL DDL）用于定义SQL模式、基本表、视图和索引的创建和撤消操作。
（2）数据操纵。（SQL DML）数据操纵分成数据查询和数据更新两类。数据更新又分成插入、删除、和修改三种操作。
（3）数据控制。包括对基本表和视图的授权，完整性规则的描述，事务控制等内容。
（4）嵌入式SQL的使用规定。涉及到SQL语句嵌入在宿主语言程序中使用的规则。

多版本并发控制 (Multiversion concurrency control)


# mysql 有那些存储引擎，有哪些区别
InnoDB ：如果要提供提交、回滚、崩溃恢复能力的事务安全（ACID兼容）能力，并要求实现并发控制，InnoDB是一个好的选择.
InnoDB 和 MyISAM之间的区别：
1. InnoDB支持事务，而MyISAM不支持
2. InnoDB支持行级锁，而MyISAM支持表级锁
3. InnoDB支持MVCC, 而MyISAM不支持
4. InnoDB支持外键，而MyISAM不支持
5. InnoDB支持崩溃恢复，而MyISAM不支持
6. InnoDB不支持全文索引，而MyISAM支持

MyISAM：如果数据表主要用来插入和查询记录，则MyISAM（但是不支持事务）引擎能提供较高的处理效率

Memory：如果只是临时存放数据，数据量不大，并且不需要较高的数据安全性，可以选择将数据保存在内存中的Memory引擎，MySQL中使用该引擎作为临时表，存放查询的中间结果。数据的处理速度很快但是安全性不高。

# mysql 索引在什么情况下会失效
- 索引本身失效：比如更改表
- 对索引字段做函数操作，可能会破坏索引值的有序性，因此优化器就决定放弃走树搜索功能。如：条件字段函数操作，隐式类型转换，隐式字符编码转换，对索引列进行运算
- 跳过索引中的列。最佳左前缀法则——如果索引了多列，要遵守最左前缀法则。指的是查询要从索引的最左前列开始并且不跳过索引中的列。
- 如果条件中有or
- like查询是以通配符%开头
- 在MYSQL使用不等于（<,>,!=）的时候无法使用索引，会导致索引失效。
- is null或者is not null 也会导致无法使用索引。

# mysql 索引模型
常见的有哈希表、有序数组和搜索树
- 哈希表这种结构适用于只有等值查询的场景，对于区间查询是无法直接通过索引查询的，就需要全表扫描。
- 有序数组在等值查询和范围查询场景中的性能就都非常优秀，但如果需要更新代价太高，因此有序数组索引只适用于静态存储引擎
- InnoDB 使用了 B+ 树索引模型，所以数据都是存储在 B+ 树中的。每一个索引在 InnoDB 里面对应一棵 B+ 树。由于在读写上的性能优点，以及适配磁盘的访问模式，已经被广泛应用在数据库引擎中了。在 MySQL 中，索引是在存储引擎层实现的。

# mysql 索引类型
根据叶子节点的内容，索引类型分为主键索引和非主键索引。
- 主键索引的叶子节点存的是整行数据。在 InnoDB 里，主键索引也被称为聚簇索引（clustered index）。
- 非主键索引的叶子节点内容是主键的值。在 InnoDB 里，非主键索引也被称为二级索引（secondary index）。由于 InnoDB 是索引组织表，一般情况下建议你创建一个自增主键，这样非主键索引占用的空间最小。

非主键索引需要先得到主键的值，再通过主键索引取得数据内容（回到主键索引树搜索的过程，称为回表）。因此基于非主键索引的查询需要多扫描一棵索引树。我们在应用中应该尽量使用主键查询。

# mysql 索引优化

1. 覆盖索引：如果一个索引包含（或者说覆盖）所有需要查询的字段值，我们称为覆盖索引。覆盖索引不需要回表，可以减少树的搜索次数，显著提升查询性能，所以使用覆盖索引是一个常用的性能优化手段。
2. 最左前缀：B+ 树这种索引结构，可以利用索引的“最左前缀”，来定位记录。只要满足最左前缀，就可以利用索引来加速检索。这个最左前缀可以是联合索引的最左 N 个字段，也可以是字符串索引的最左 M 个字符。
   第一原则是，如果通过调整顺序，可以少维护一个索引，那么这个顺序往往就是需要优先考虑采用的。所以当我们创建一个联合索引的时候，如(key1,key2,key3)，相当于创建了（key1）、(key1,key2)和(key1,key2,key3)三个索引，这就是最左匹配原则。
3. 索引下推：MySQL 5.6 引入的索引下推优化（index condition pushdown)，可以在索引遍历过程中，对索引中包含的字段先做判断，直接过滤掉不满足条件的记录，减少回表次数。

# mysql 主从同步
一个事务日志同步的完整过程是这样的：
1. 在备库 B 上通过 change master 命令，设置主库 A 的 IP、端口、用户名、密码，以及要从哪个位置开始请求 binlog，这个位置包含文件名和日志偏移量。
2. 在备库 B 上执行 start slave 命令，这时候备库会启动两个线程，就是图中的 io_thread 和 sql_thread。其中 io_thread 负责与主库建立连接。
3. 主库 A 校验完用户名、密码后，开始按照备库 B 传过来的位置，从本地读取 binlog，发给 B。
4. 备库 B 拿到 binlog 后，写到本地文件，称为中转日志（relay log）。
5. sql_thread 读取中转日志，解析出日志里的命令，并执行。

在满足数据可靠性的前提下，MySQL 高可用系统的可用性，是依赖于主备延迟的。延迟的时间越小，在主库故障的时候，服务恢复需要的时间就越短，可用性就越高。

一主多从的设置，一般用于读写分离，主库负责所有的写入和一部分读，其他的读请求则由从库分担。
