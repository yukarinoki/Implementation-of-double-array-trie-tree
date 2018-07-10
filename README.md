# Implementation-of-double-array-trie-tree

Double-Array Articles (http://nanika.osonae.com/DArray/index.html)
を参考にして、ダブル配列によるTrie木を実装した。

Demo.cはダブル配列（ Double-Array ）の概要　(http://nanika.osonae.com/DArray/dary.html)に載っている"図 1 ： "bird", "bison", "cat" を登録したトライとダブル配列"を完全に再現する。

このプログラムは初めにまとまってソートされて重複のないvector<string>を受け取りTrie木を構成する。動的な更新には対応していない。

計算量は、O(文字列集合の合計文字数)である。
その再帰でみる文字の集合を得る部分(csetを作る部分)は二分探索を用いて、より高速化できると思われる。

classにしたものも実装する予定


＊実行の様子

yukarinoki@yukarinoki-OptiPlex-9010:~/sandbox$ g++ -std=c++14 demo.c
yukarinoki@yukarinoki-OptiPlex-9010:~/sandbox$ ./a.out
bird#
bison#
cat#
base: 1, cn: 0 fidx: 0, lidx: 2
 1
 1
 0

base: 4, cn: 1 fidx: 0, lidx: 1
 1  2  3  4  5
 1  0  0  0  0
 0  0  0  1  1

base: 7, cn: 2 fidx: 0, lidx: 1
 1  2  3  4  5  6  7
 1  0  0  1  0  0  0
 0  0  0  1  1  0  4

base: 10, cn: 3 fidx: 0, lidx: 0
 1  2  3  4  5  6  7  8  9 10 11
 1  0  0  1  0  0  1  0  0  0  0
 0  0  0  1  1  0  4  0  0  7  7

base: 6, cn: 4 fidx: 0, lidx: 0
 1  2  3  4  5  6  7  8  9 10 11
 1  0  0  1  0  0  1  0  0  1  0
 0  0  0  1  1 10  4  0  0  7  7

base: 11, cn: 3 fidx: 1, lidx: 1
 1  2  3  4  5  6  7  8  9 10 11
 1 -1  0  1  0  1  1  0  0  1  0
 0  6  0  1  1 10  4  0  0  7  7

base: 9, cn: 4 fidx: 1, lidx: 1
 1  2  3  4  5  6  7  8  9 10 11
 1 -1  0  1  0  1  1  0  0  1  1
 0  6  0  1  1 10  4  0 11  7  7

base: 8, cn: 5 fidx: 1, lidx: 1
 1  2  3  4  5  6  7  8  9 10 11
 1 -1  0  1  0  1  1  0  1  1  1
 0  6  0  1  1 10  4  9 11  7  7

base: 5, cn: 1 fidx: 2, lidx: 2
 1  2  3  4  5  6  7  8  9 10 11
 1 -1 -2  1  0  1  1  2  1  1  1
 0  6  8  1  1 10  4  9 11  7  7

base: 12, cn: 2 fidx: 2, lidx: 2
 1  2  3  4  5  6  7  8  9 10 11 12
 1 -1 -2  1 10  1  1  2  1  1  1  0
 0  6  8  1  1 10  4  9 11  7  7  5

base: 13, cn: 3 fidx: 2, lidx: 2
 1  2  3  4  5  6  7  8  9 10 11 12 13
 1 -1 -2  1 10  1  1  2  1  1  1  2  0
 0  6  8  1  1 10  4  9 11  7  7  5 12

 1  2  3  4  5  6  7  8  9 10 11 12 13 14
 1 -1 -2  1 10  1  1  2  1  1  1  2 13 -3
 0  6  8  1  1 10  4  9 11  7  7  5 12 13
