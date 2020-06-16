---
title: "Mysql"
date: 2020-06-14T12:01:18+08:00
draft: true
---

MySQL慢查询就是在日志中记录运行比较慢的SQL语句，这个功能需要开启才能用。

在MySQL的配置文件my.cnf中写上：

long_query_time = 10
log-slow-queries = /var/lib/mysql/mysql-slow.log

long_query_time是指执行超过多久的SQL会被日志记录下来，这里是10 秒。
log-slow-queries设置把日志写在那里（例子中慢查询日志会写到文件/var/lib/mysql/mysql-slow.log中），为空的时候，系统会给慢查询日志赋予主机名，并加上slow.log。如果设置了参数log-long-format ，那么所有没有使用索引的查询也将被记录。

这是一个非常有用的日志。它对于性能的影响不大（假设所有查询都很快），并且强调了那些最需要注意的查询（丢失了索引或索引没有得到最佳应用）




电话号码就像地址，只是以数字的形式呈现出来，存储成varchar类型以后，方面正则匹配，格式化，和一般的字符化处理。Strings & VARCHAR.