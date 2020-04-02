---
title: "Batch_code"
date: 2020-01-08T17:28:06+08:00
draft: true
---

## 添加注释

Use :: or REM
```bat
::   commenttttttttttt
REM  commenttttttttttt
```
If you use inline, you need to add & character:
your commands here      & ::  commenttttttttttt
Inside nested logic (IF/ELSE, FOR loops, etc...) use REM because :: gives an error.
:: may fail within setlocal ENABLEDELAYEDEXPANSION

link: <https://stackoverflow.com/questions/11269338/how-to-comment-out-add-comment-in-a-batch-cmd>