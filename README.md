# Implementation-of-double-array-trie-tree

Double-Array Articles (http://nanika.osonae.com/DArray/index.html)
を参考にして、ダブル配列によるTrie木を実装した。

Demo.cはダブル配列（ Double-Array ）の概要　(http://nanika.osonae.com/DArray/dary.html)に載っている"図 1 ： "bird", "bison", "cat" を登録したトライとダブル配列"を完全に再現する。

このプログラムは初めにまとまってソートされて重複のないvector<string>を受け取りTrie木を構成する。動的な更新には対応していない。

計算量は、O(文字列集合の合計文字数)である。
その再帰でみる文字の集合を得る部分(csetを作る部分)は二分探索を用いて、より高速化できると思われる。