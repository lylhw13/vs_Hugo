---
title: "Http"
date: 2018-12-13T21:38:11+08:00
draft: true
---

HTTP 权威指南
```text
<scheme>://<user>:<password>@<host>:<port>/<path>;<params>?<query>#<frag>
```
abbreviation | original
--- | ---
SMTP | Simple Mail Transfer Protocol
FTP | File Transfer Protocol
HTTPS | Hypertext Transfer Protocol Secure
MIME | Multipurpose Internet Mail Extension
URI | Uniform Resource Identifier
TCP | Transmission Control Protocol
IP | Internet Protocol
DNS | Domain Name Service

现在，几乎所有的 URI 都是 URL。

Content-Type 首部说明了文档的 MIME 类型。
网关扮演的是“协议转换器”的角色。

如果一个事务，不管是执行一次还是很多次，得到的结果都相同，这个事务就是幂等的。客户端不应该以管道化方式传送非幂等请求。


http 默认端口80

https 默认端口443

check memory leak
use [memwatch](https://www.npmjs.org/package/memwatch).
refer to <https://codeforgeek.com/2014/10/express-complete-tutorial-part-5/>

test server under pressure
use `siege`
refer to <https://codeforgeek.com/2015/01/nodejs-mysql-tutorial/>