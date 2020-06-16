---
title: "ModuleNotFoundError: No module named 'Crypto'"
date: 2020-05-08T21:45:10+08:00
draft: true
---

```python
from Crypto.Cipher import AES
```
运行上面语句会报错：
>from Crypto.Cipher import AES  
>ModuleNotFoundError: No module named 'Crypto'

解决办法，如果安装有crypto, pycrypto, pycryptodome, 先将其全部卸载，然后再重新安装 pycryptodome.

```sh
pip uninstall crypto pycrypto pycryptodome
pip install pycryptodome
```
鉴于有说pycrypto不再安全，建议使用pycryptodome。pycyrptodome 是pycrypto的分支，在安全性方面有较大提升。

@[TOC](使用python进行AES对称加密解密)
# 常用的对称加密算法简介
有时需要对数据进行对称加解密，常用的有：
- DES（Data Encryption Standard，即数据加密标准）。
	由于这种加密算法已经可以被暴力破解，所以已经不再安全。因此除了用它来解密以前对密文外，不应该再使用DES了。
- AES（Advanced Encryption Standard，即高级加密标准），已经取代DES成为新标准的对称加密算法。
	AES加密法属于Rijndael加密法的子集。区别为：
	- 在AES的规格中，区块长度固定为128比特，密钥长度只有128，192和256比特三种选择。
	- Rijndael的区块长度和密钥长度可以是位于128比特到256比特之间且为32比特整数倍到长度。

## 经典的对称区块加密模式
区块加密采用对称密钥来加密固定且较短的长度（区块）的数据。
- ECB mode （Electionic CodeBook）
	最基本但是安全性最差的加密操作模式，`不应该再使用此模式`。
- CBC mode（Ciphertext Block Chaining）
- CTR mode（Count TeR mode）
	用于并行运算，
- CFB mode（Cipher FeedBack）
- OPB mode（Output FeedBack）
- OpenPGP mode
## 现代的对称区块加密模式
经典的操作模式，比如CBC mode只能保证机密性，但是不能保证完整性。
基于这个原因，经典模式经常会和MAC算法（比如Crypto.Hash.HMAC）搭配使用，但是这种结合不够直观，有效和安全。
因此就有了

 - CCM mode（Counter with CBC-MAC)
	 只能和128比特的AES加密算法搭配使用。
 - EAX mode（An AEAD mode designed for NIST）
-	GCM mode（Galois/Counter Mode）
	只能和128比特的AES加密算法搭配使用。
- SIV mode（Synthetic Initialization Vector (SIV)）
	只能和128比特的AES加密算法搭配使用。
- OCB mode（Offset CodeBook mode）
	只能和128比特的AES加密算法搭配使用。
# 使用示例
## 安装依赖库
鉴于pycrypto已不再安全，建议使用pycryptodome。pycyrptodome 是pycrypto的分支，在安全性方面有较大提升。
```python
pip install pycryptodome
```
## 示例
以CBC模式为例：
### 以经典的CBC模式为例
```python
# -*- coding:utf-8  -*-
import json
```
输出结果为
```txt
Encryption is {"iv": "U9VNpFMMRC5vLjDh14f72g==", "ciphertext": "hXDgGhzs70T5PoIwiYOxDg=="}
The message was:  你的密文
```
### 以现代的OCB模式为例
## 可能问题
```python
from Crypto.Cipher import AES
```
运行上面语句会报错：
>from Crypto.Cipher import AES  
>ModuleNotFoundError: No module named 'Crypto'

可能原因是安装有crypto, pycrypto, pycryptodome中的多个。
解决办法：先将其全部卸载，然后再重新安装 pycryptodome.

```sh
pip uninstall crypto pycrypto pycryptodome
pip install pycryptodome
```



 [1]: http://meta.math.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference
 [2]: https://mermaidjs.github.io/
 [3]: https://mermaidjs.github.io/
 [4]: http://adrai.github.io/flowchart.js/