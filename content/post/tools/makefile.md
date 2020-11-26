---
title: "Makefile"
date: 2020-11-21T16:29:28+08:00
draft: true
---

# chapter 3
By default, when make looks for the makefile, it tries the following names, in order: 
- ‘GNUmakefile’ Only work for GUN make
- ‘makefile’
- ‘Makefile’    recommend

# chapter 4

We can use wildcards in the target, prerequisites, or commands.
Valid wildcards are *, ?, [...]

The wildcard characters in make are ‘*’, ‘?’ and ‘[...]’, the same as in the Bourne shell. 

前面加反斜杠 \ 可以关闭通配符


The value of the make variable VPATH specifies a list of directories that make should search.