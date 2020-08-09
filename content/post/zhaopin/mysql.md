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




mysql 主从同步怎么搞的？分哪几个过程？如果有一台新机器要加到从机里，怎么个过程。
乐观锁与悲观锁的区别？
binlog 日志是 master 推的还是 salve 来拉的？

# mysql 有那些存储引擎，有哪些区别
InnoDB ：如果要提供提交、回滚、崩溃恢复能力的事务安全（ACID兼容）能力，并要求实现并发控制，InnoDB是一个好的选择.
InnoDB 和 MyISAM之间的区别：
1. InnoDB支持事务，而MyISAM不支持
2. InnoDB支持行级锁，而MyISAM支持表级锁
3. InnoDB支持MVCC, 而MyISAM不支持
4. InnoDB支持外键，而MyISAM不支持
5. InnoDB不支持全文索引，而MyISAM支持

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
- 哈希表这种结构适用于只有等值查询的场景
- 有序数组在等值查询和范围查询场景中的性能就都非常优秀，但如果需要更新代价太高，因此有序数组索引只适用于静态存储引擎
- N 叉树由于在读写上的性能优点，以及适配磁盘的访问模式，已经被广泛应用在数据库引擎中了。在 MySQL 中，索引是在存储引擎层实现的

# mysql 索引类型
根据叶子节点的内容，索引类型分为主键索引和非主键索引。
- 主键索引的叶子节点存的是整行数据。在 InnoDB 里，主键索引也被称为聚簇索引（clustered index）。
- 非主键索引的叶子节点内容是主键的值。在 InnoDB 里，非主键索引也被称为二级索引（secondary index）。