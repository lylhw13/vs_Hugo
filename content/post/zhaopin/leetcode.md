---
title: "Leetcode"
date: 2020-06-13T23:13:17+08:00
draft: true
---

典型写法

消除低位的1
k = k ^ (k - 1);

k & -k; //取最后一位的1

test cases
- expected input
- empty input
- malformed input
- large input
- null input
- other edge cases


tiny url
design twitter

mvc

data flow

贪心算法（又称贪婪算法）是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的是在某种意义上的局部最优解。

贪心算法不是对所有问题都能得到整体最优解，关键是贪心策略的选择，选择的贪心策略必须具备无后效性，即某个状态以前的过程不会影响以后的状态，只与当前状态有关。


//要回顾的题
lru
lfu

# 并查集
```c++
class UnionFind{
private:
    vector<int> root;
public:
    UnionFind(int N):root(N){
        for(int i=0; i< N; ++i) {
            root[i] = i;
        }
    }

    int find(int p) {
        while(p != root[p]) {
            //root[p] = root[root[p]];    //路径压缩
            p = root[p];
        }
        return root[p];
    }
    bool isConnect(int p, int q) {
        return find(p) == find(q);
    }
    void unionTwo(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        root[rootp] = rootq;
    }
};
```

