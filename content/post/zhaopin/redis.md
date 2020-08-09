---
title: "Redis"
date: 2020-08-08T15:06:47+08:00
draft: true
---

redis 持久化有哪几种方式，怎么选？
redis 主从同步是怎样的过程？
redis 的 zset 怎么实现的？
redis key 的过期策略
redis 哨兵和集群
hashmap 是怎样实现的？

让你设计一个限流的系统怎么做？ 令牌桶
让你设计一个延时任务系统怎么做 说了两个方案，一个是使用 redis 的 ZSET 来实现，考虑分片来抗高并发，使用 redis 的持久化来实现落地，使用 redis 的哨兵实现故障转移。 一个是使用时间轮的方法。