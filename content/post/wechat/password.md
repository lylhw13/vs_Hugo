---
title: "Password"
date: 2018-12-04T22:32:48+08:00
draft: true
---

## 清理内容

### 使用说明：
1. 设定一个种子值
2. 输入口令值，并产生一个密码。

### 原理说明：
1. 这个种子会经过多次SHA256单向加密函数加密过以后，产生一个64位的哈希值，保存在本地，不会保存种子的明文。用户可以用只有自己知道的一段文字作为种子的值，这段文字可以写在纸上妥善保存在其他地方。
2. 然后，由每个口令值经过和种子的哈希值的HMAC_SHA256单向加密后，产生一个64位的哈希值，通过截取哈希值的前12位，产生一个密码。

注意：
1，口令在输入结束后，5分钟删除。
2，密码在产生以后，1分钟删除。
3，两次密码产生的时间间隔为1分钟。
4，口令和密码在复制一次后删除。
5. 这里输入的种子和口令可以是任意字符，不仅限于数字和字母。


安全性：
1，由于SHA256和HMAC_SHA256函数具有良好的抗碰撞性，因此不可能通过哈希值推断出口令值和种子值。
2，种子值和口令值分开保存，能够提高密码的安全性。
3，通过多个生成的密码，不可能推断出其他密码。因此不用担心密码在网站端的泄漏。
4，本应用属于本地应用，不包含任何网络连接。

优势：
1，安全性高。
2，记忆难度低。这里无需记忆密码，只需记得口令即可。

优势：
降低密码的设置难度，当用户要为新网站设定密码时候，要面对两种选择，是设定一个和其他网站都一样的密码，
还是和其他网站不一样的特殊密码，前者一旦一个密码泄漏，相当于所有密码都泄漏了；后者则增加了密码记忆的难度。

每个人的密码我感觉应该分为两类，第一类和钱财直接挂钩的极为重要的密码，这种密码毕竟属于少数，应该记在脑子里；
第二类则属于日常应用的密码，数量庞大，这类密码应区别于第一类密码，不能混为一谈。
但是第二类密码，不同的人，有不同的记忆方式，有的人全部设为一样，这种只要有一个泄漏，就相当于全部泄漏；
第二类，有人设定固定的密码组合方式，可以根据使一个密码对应一类网址，但是这种记忆负担大，而且可以从一个或多个密码推断出密码的组合规则；

使用本工具，可以提前设定一个种子，这个种子使用自己才知道的信息，

