# LeetCode Practice Record

This repository contains my solutions and explanations for various LeetCode problems. 

The problems are organized into directories based on the main technique or data structure needed to solve them.

## Table of Contents

### Data structure

- [Array](#array)
- [Linked List](#linked-list)
- [Hash Table](#hash-table)
- [Set](#set)
- [String](#string)
- [Stack](#stack)
- [Queue](#queue)
- [Heap](#heap)
- [Binary Tree](#binary-tree)
- [Trie](#trie)
- [Monotonic Queue](#monotonic-queue)
- [Disjoint Set](#disjoint-set)

### Algorithm

- [LeetCode Practice Record](#leetcode-practice-record)
  - [Table of Contents](#table-of-contents)
    - [Data structure](#data-structure)
    - [Algorithm](#algorithm)
- [刷題訓練的四大能力](#刷題訓練的四大能力)
- [刷題方法](#刷題方法)
- [Data Structure](#data-structure-1)
  - [Array](#array)
  - [Hash Table](#hash-table)
  - [Linked List](#linked-list)
  - [Set](#set)
  - [String](#string)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Binary Tree](#binary-tree)
  - [Tree](#tree)
  - [Heap](#heap)
  - [Trie](#trie)
  - [Monotonic Queue](#monotonic-queue)
  - [Disjoint Set](#disjoint-set)
- [演算法策略](#演算法策略)
  - [Sorting](#sorting)
  - [Binary Search](#binary-search)
  - [Two-Pointers](#two-pointers)
  - [Sliding Window](#sliding-window)
  - [Bit Operation](#bit-operation)
  - [Backtracking](#backtracking)
  - [Recursion](#recursion)
  - [Graph Algorithm](#graph-algorithm)
  - [Greedy](#greedy)
  - [Dynamic Programming](#dynamic-programming)
- [Divide and Conquer](#divide-and-conquer)
- [Reference：](#reference)

# 刷題訓練的四大能力

- 抽象化能力：將題序看懂，並了解題序中的限制，問題和其他問題的結構是否有相似之處，是否有數學模型能套用到該問題上。
- 演算法、資料結構能力：題目的結構適合使用哪一個演算法策略來解，而在中間需要對資料進行什麼操作，是否有合適的資料結構來儲存，以節省這些資料操作的時間。
- 實作能力：如何將演算法轉成實際的程式語言，使用的程式語言中是否有既有的語法或函式庫來實作，是否有邊界條件的測資無法通過。
- 溝通能力：如何在 coding 過程中，將自己的想法清楚表達給面試官，在面試官給的題敘不夠詳盡、清楚時，是否可以透過溝通，將題目的需求和限制釐清

# 刷題方法

- 看懂題目的敘述、測資，手動依照題目推演過測資
- 思考 brute-force 的解法，注意各種邊界條件，邏輯縝密性
- 思考更近一步，如何優化時間複雜度或空間複雜度
- 將各種思路口頭敘述一遍，表達清楚（英語）
- 扮演面試官，在出題過程中，是否有什麼變形，是否有什麼假設，哪個解法的障礙等等
- 看別人的 discussion 和官方題解，是否有比自己更好的作法

**刷題不是流水帳，不是解過一題是一題，重點在磨練這四個能力，不是在背題。**

# Data Structure

## Array

- Dynamic Array (Vector) Implementation: [C++](./Array/Implementations/Dynamic%20Array/main.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)| [C++](./Array/217.%20Contains%20Duplicate/main.cpp) | | Easy | 2024/06/12 | [x] | [ ] |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/)| [C++](./Array/238.%20Product%20of%20Array%20Except%20Self/main.cpp) | | Medium | 2024/06/29 | [x]  | [ ] |
| 350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/description/)| [C++](./Array/350.%20Intersection%20of%20Two%20Arrays%20II/main.cpp) | | Easy | 2024/07/02 | [x]  | [ ] |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/)| [C++](./Array/42.%20Trapping%20Rain%20Water/main.cpp) | | Hard | 2024/07/02 | [x]  | [ ] |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)| [C++](./Array/80.%20Remove%20Duplicates%20from%20Sorted%20Array%20II/main.cpp) | | Medium | 2024/07/02 | [x]  | [ ] |
| 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)| [C++](./Array/73.%20Set%20Matrix%20Zeroes/main.cpp) | | Medium | 2024/07/03 | [x]  | [ ] |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | [C++](./Array/56.%20Merge%20Intervals/main.cpp) | | Medium | 2024/07/04 | [x]  | [ ] |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval/description/) | [C++](./Array/57.%20Insert%20Interval/main.cpp) | | Medium | 2024/07/04 | [x]  | [ ] |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/description/) | [C++](./Array/189.%20Rotate%20Array/main.cpp) | | Medium | 2024/07/04 | [x]  | [ ] |
| 1701 | [Average Waiting Time](https://leetcode.com/problems/average-waiting-time/) | [C++](./Array/1701.%20Average%20Waiting%20Time/main.cpp) | | Medium | 2024/07/09 | [x]  | [ ] |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | [C++](./Array/36.%20Valid%20Sudoku/main.cpp) | | Medium | 2024/07/10 | [x]  | [ ] |

## Hash Table

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)| [C++](./Hash%20Table/49.%20Group%20Anagrams/main.cpp) | | Medium | 2024/06/17 | [x] | [ ] |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)| [C++](./Hash%20Table/347.%20Top%20K%20Frequent%20Elements/main.cpp) | | Medium | 2024/06/17 | [x] | [ ] |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/description/)| [C++](./Hash%20Table/169.%20Majority%20Element/main.cpp) | | Easy | 2024/06/28 | [x] | [ ] |
| 380 | [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/description/)| [C++](./Hash%20Table/380.%20Insert%20Delete%20GetRandom%20O(1)/main.cpp) | | Medium | 2024/06/28 | [x] | [ ] |
| 383 | [Ransom Note](https://leetcode.com/problems/ransom-note/description)| [C++](./Hash%20Table/383.%20Ransom%20Note/main.cpp) | | Easy | 2024/07/04 | [x] | [ ] |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/) | [C++](./Hash%20Table/128.%20Longest%20Consecutive%20Sequence/main.cpp) | | Medium | 2024/07/04 | [x] | [ ] |
| 290 | [Word Pattern](https://leetcode.com/problems/word-pattern/description/) | [C++](./Hash%20Table/290.%20Word%20Pattern/main.cpp) | | Medium | 2024/07/04 | [x] | [ ] |
| 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/) | [C++](./Hash%20Table/219.%20Contains%20Duplicate%20II/main.cpp) | | Easy | 2024/07/10 | [x] | [ ] |

## Linked List

- Singly Linked List Implementation: [C++](./Linked%20List/Implementations/Singly%20Linked%20List)
- Circular Linked List Implementation: [C++](./Linked%20List/Implementations/Circular%20Linked%20List/)
- Double Linked List Implementation: [C++](./Linked%20List/Implementations/Double%20Linked%20List/)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 2095 | [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)| [C](./Linked%20List/2095.%20Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/main.c) | | Medium | 2024/02/28 | [x] | [ ] |
| 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)| [C](./Linked%20List/82.%20Remove%20Duplicates%20from%20Sorted%20List%20II/main.c) | | Medium | 2024/02/28 | [x] | [ ] |
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)| [C](./Linked%20List/25.%20Reverse%20Nodes%20in%20k-Group/main.c) | | Hard | 2024/02/29 | [x] | [ ] |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/)| [C++](./Linked%20List/92.%20Reverse%20Linked%20List%20II/main.cpp) | | Medium | 2024/04/03 | [x] | [ ] |
| 116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)| [C++](./Linked%20List/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/main.cpp) | | Medium | 2024/04/03 | [x] | [ ] |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)| [C](./Linked%20List/23.%20Merge%20k%20Sorted%20Lists/main.c) | | Hard | 2024/03/01 | [x] | [ ] |
| 2181 | [Merge Nodes in Between Zeros](https://leetcode.com/problems/merge-nodes-in-between-zeros/) | [C++](./Linked%20List/2181.%20Merge%20Nodes%20in%20Between%20Zeros/main.cpp) | | Medium | 2024/07/04 | [x] | [ ] |
| 2058 | [Find the Minimum and Maximum Number of Nodes Between Critical Points](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/) | [C++](./Linked%20List/2058.%20Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points/main.cpp) | | Medium | 2024/07/05 | [x] | [ ] |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | [C++](./Linked%20List/141.%20Linked%20List%20Cycle/main.cpp) | | Easy | 2024/07/05 | [x] | [ ] |
| 1836 | [Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/) | [C++](./Linked%20List/1836.%20Remove%20Duplicates%20From%20an%20Unsorted%20Linked%20List/main.cpp) | | Medium | 2024/07/09 | [x] | [ ] |

## Set

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## String

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 2743 | [Count Substrings Without Repeating Character](https://leetcode.com/problems/count-substrings-without-repeating-character/description/) | [C++](./String/2743.%20Count%20Substrings%20Without%20Repeating%20Character/main.cpp) | | Medium | 2024/06/28 | [x] | [ ] |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/) | [C++](./String/13.%20Roman%20to%20Integer/main.cpp) | | Easy | 2024/07/02 | [x] | [ ] |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/) | [C++](./String/12.%20Integer%20to%20Roman/main.cpp) | | Medium | 2024/07/02 | [x] | [ ] |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/) | [C++](./String/58.%20Length%20of%20Last%20Word/main.cpp) | | Easy | 2024/07/02 | [x] | [ ] |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/) | [C++](./String/14.%20Longest%20Common%20Prefix/main.cpp) | | Easy | 2024/07/02 | [x] | [ ] |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/) | [C++](./String/151.%20Reverse%20Words%20in%20a%20String/main.cpp) | | Medium | 2024/07/02 | [x] | [ ] |
| 6 | [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/) | [C++](./String/6.%20Zigzag%20Conversion/main.cpp) | | Medium | 2024/07/03 | [x] | [ ] |
| 28 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | [C++](./String/28.%20Find%20the%20Index%20of%20the%20First%20Occurrence%20in%20a%20String/main.cpp) | | Easy | 2024/07/03 | [x] | [ ] |
| 1598 | [Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/) | [C++](./String/1598.%20Crawler%20Log%20Folder/main.cpp) | | Easy | 2024/07/10 | [x] | [ ] |

## Stack

- Stack Implementation: [C++](./Stack/Implementation/Stack.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | [C++](./Stack/225.%20Implement%20Stack%20using%20Queues/main.cpp) | | Easy | 2024/03/12 | [x] | [ ] |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [C++](./Stack/20.%20Valid%20Parentheses/main.cpp) | | Easy | 2024/03/12 | [x] | [ ] |
| 71 | [Simplify Path](https://leetcode.com/problems/simplify-path/) | [C++](./Stack/71.%20Simplify%20Path/main.cpp) | | Medium | 2024/03/13 | [x] | [ ] |
| 1249 | [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) | [C++](./Stack/1249.%20Minimum%20Remove%20to%20Make%20Valid%20Parentheses/main.cpp) | | Medium | 2024/03/13 | [x] | [ ] |
| 227 | [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | [C++](./Stack/227.%20Basic%20Calculator%20II/main.cpp) | | Medium | 2024/03/14 | [x] | [ ] |
| 155 | [Min Stack](https://leetcode.com/problems/min-stack/description) | [C++](./Stack/155.%20Min%20Stack/main.cpp) | | Hard | 2024/03/25 | [x] | [ ] |
| 1193 | [Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/) | [C++](./Stack/1193.%20Reverse%20Substrings%20Between%20Each%20Pair%20of%20Parentheses/main.cpp) | | Medium | 2024/07/11 | [x] | [ ] |
| 2751 | [Robot Collisions](https://leetcode.com/problems/robot-collisions/) | [C++](./Stack/2751.%20Robot%20Collisions/main.cpp) | | Hard | 2024/07/13 | [x] | [ ] |
| 726 | [Number of Atoms](https://leetcode.com/problems/number-of-atoms/) | [C++](./Stack/726.%20Number%20of%20Atoms/main.cpp) | | Hard | 2024/07/14 | [x] | [ ] |
| 224 | [Basic Calculator](https://leetcode.com/problems/basic-calculator) | [C++](./Stack/224.%20Basic%20Calculator/main.cpp) | | Hard | 2024/03/14 | [ ] | [ ] |

## Queue

- Queue Implementation by Singly Linked-list: [C++](./Queue/Implementation/Queue.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)| [C++](./Queue/232.%20Implement%20Queue%20using%20Stacks/main.cpp) | | Easy | 2024/03/12 | [x] | [ ] |
| 362 | [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/description/)| [C++](./Queue/362.%20Design%20Hit%20Counter/main.cpp) | | Medium | 2024/03/17 | [x] | [ ] |
| 387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/description/)| [C++](./Queue/387.%20First%20Unique%20Character%20in%20a%20String/main.cpp) | | Easy | 2024/03/18 | [x] | [ ] |
| 353 | [Design Snake Game](https://leetcode.com/problems/design-snake-game/description/)| [C++](./Queue/353.%20Design%20Snake%20Game/main.cpp) | | Medium | 2024/03/18 | [x] | [ ] |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)| [C++](./Queue/239.%20Sliding%20Window%20Maximum/main.cpp) | | Hard | 2024/03/19 | [ ] | [ ] |

## Binary Tree

- Morris Traversal: [C++](./Binary%20Tree/Implementations/Morris%20Traversal/main.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | [C++](./Binary%20Tree/94.%20Binary%20Tree%20Inorder%20Traversal/main.cpp) | | Easy | 2024/03/21 | [x] | [ ] |
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | [C++](./Binary%20Tree/98.%20Validate%20Binary%20Search%20Tree/main.cpp) | | Medium | 2024/03/21 | [x] | [ ] |
| 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/) | [C++](./Binary%20Tree/101.%20Symmetric%20Tree/main.cpp) | | Easy | 2024/03/22 | [x] | [ ] |
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | [C++](./Binary%20Tree/102.%20Binary%20Tree%20Level%20Order%20Traversal/main.cpp) | | Medium | 2024/03/22 | [x] | [ ] |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | [C++](./Binary%20Tree/104.%20Maximum%20Depth%20of%20Binary%20Tree/main.cpp) | | Easy | 2024/03/22 | [x] | [ ] |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [C++](./Binary%20Tree/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal/main.cpp) | | Medium | 2024/03/22 | [x] | [ ] |
| 108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/) | [C++](./Binary%20Tree/108.%20Convert%20Sorted%20Array%20to%20Binary%20Search%20Tree/main.cpp) | | Medium | 2024/03/23 | [x] | [ ] |
| 114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | [C++](./Binary%20Tree/114.%20Flatten%20Binary%20Tree%20to%20Linked%20List/main.cpp) | | Medium | 2024/03/23 | [x] | [ ] |
| 145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | [C++](./Binary%20Tree/145.%20Binary%20Tree%20Postorder%20Traversal/main.cpp) | | Easy | 2024/03/26 | [x] | [ ] |
| 270 | [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/description/) | [C++](./Binary%20Tree/270.%20Closest%20Binary%20Search%20Tree%20Value/main.cpp) | | Easy | 2024/03/26 | [x] | [ ] |
| 95 | [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/description/) | [C++](./Binary%20Tree/95.%20Unique%20Binary%20Search%20Trees%20II/main.cpp) | | Medium | 2024/03/26 | [x] | [ ] |
| 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/) | [C++](./Binary%20Tree/110.%20Balanced%20Binary%20Tree/main.cpp) | | Easy | 2024/03/26 | [x] | [ ] |
| 222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/) | [C++](./Binary%20Tree/222.%20Count%20Complete%20Tree%20Nodes/main.cpp) | | Medium | 2024/03/26 | [x] | [ ] |
| 99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/) | [C++](./Binary%20Tree/99.%20Recover%20Binary%20Search%20Tree/main.cpp) | | Medium | 2024/03/27 | [x] | [ ] |
| 100 | [Same Tree](https://leetcode.com/problems/same-tree/description/) | [C++](./Binary%20Tree/100.%20Same%20Tree/main.cpp) | | Easy | 2024/07/06 | [x] | [ ] |
| 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/) | [C++](./Binary%20Tree/226.%20Invert%20Binary%20Tree/main.cpp) | | Easy | 2024/07/06 | [x] | [ ] |
| 129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/) | [C++](./Binary%20Tree/129.%20Sum%20Root%20to%20Leaf%20Numbers/main.cpp) | | Medium | 2024/07/10 | [x] | [ ] |
| 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) | [C++](./Binary%20Tree/124.%20Binary%20Tree%20Maximum%20Path%20Sum/main.cpp) | | Hard | 2024/07/10 | [x] | [ ] |
| 173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [C++](./Binary%20Tree/173.%20Binary%20Search%20Tree%20Iterator/main.cpp) | | Medium | 2024/07/11 | [x] | [ ] |
| 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/) | [C++](./Binary%20Tree/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree/main.cpp) | | Medium | 2024/07/11 | [x] | [ ] |
| 530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/) | [C++](./Binary%20Tree/530.%20Minimum%20Absolute%20Difference%20in%20BST/main.cpp) | | Easy | 2024/07/11 | [x] | [ ] |
| 230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/) | [C++](./Binary%20Tree/230.%20Kth%20Smallest%20Element%20in%20a%20BST/main.cpp) | | Medium | 2024/07/11 | [x] | [ ] |
| 637 | [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/description/) | [C++](./Binary%20Tree/637.%20Average%20of%20Levels%20in%20Binary%20Tree/main.cpp) | | Easy | 2024/07/12 | [x] | [ ] |
| 2196 | [Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/) | [C++](./Binary%20Tree/2196.%20Create%20Binary%20Tree%20From%20Descriptions/main.cpp) | | Medium | 2024/07/15 | [x] | [ ] |
| 1740 | [Find Distance in a Binary Tree](https://leetcode.com/problems/find-distance-in-a-binary-tree/) | [C++](./Binary%20Tree/1740.%20Find%20Distance%20in%20a%20Binary%20Tree/main.cpp) | | Medium | 2024/07/15 | [x] | [ ] |
| 2096 | [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | [C++](./Binary%20Tree/2096.%20Step-By-Step%20Directions%20From%20a%20Binary%20Tree%20Node%20to%20Another/main.cpp) | | Medium | 2024/07/16 | [x] | [ ] |
| 1110 | [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/description/) | [C++](./Binary%20Tree/1110.%20Delete%20Nodes%20And%20Return%20Forest/main.cpp) | | Medium | 2024/07/17 | [x] | [ ] |
| 1530 | [Number of Good Leaf Nodes Pairs](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/) | [C++](./Binary%20Tree/1530.%20Number%20of%20Good%20Leaf%20Nodes%20Pairs/main.cpp) | | Medium | 2024/07/18 | [ ] | [ ] |

## Tree

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Heap

- Min Heap Implementation: [C](./Heap/Implementations/Min-Heap/MinHeap.h)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)| [C++](./Heap/703.%20Kth%20Largest%20Element%20in%20a%20Stream/main.cpp) | | Easy | 2024/03/04 | [ ] | [ ] |

## Trie

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)| [C++](./Tree/208.%20Implement%20Trie%20(Prefix%20Tree)/main.cpp) | | Medium | 2024/01/18 | [x] | [ ] |

## Monotonic Queue

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Disjoint Set

- Linked-list implementation: [main.cpp](./Disjoint%20Set/Implementations/Linked%20List%20Implementation/main.cpp)
- Disjoint-sets Forest implementation: [main.cpp](./Disjoint%20Set/Implementations/Disjoint%20Sets%20Forest%20Implementation/main.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)| [C++](./Graph/547.%20Number%20of%20Provinces/main.cpp) | | Medium | 2024/01/27 | [x] | [ ] |
| 261 | [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)| [C++](./Graph/261.%20Graph%20Valid%20Tree/main.cpp) | | Medium | 2024/01/27 | [x] | [ ] |

# 演算法策略

## Sorting

- Insertion Sort Implementation: [InsertionSort.c](./Sorting/Implementations/Array/InsertionSort.c)
- Selection Sort Implementation: [SelectionSort.c](./Sorting/Implementations/Array/SelectionSort.c)
- Bubbble Sort Implementation: [BubbleSort.c](./Sorting/Implementations/Array/BubbleSort.c)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 75 | [Sort Colors](https://leetcode.com/problems/sort-colors/description/)| [C++](./Sorting/75.%20Sort%20Colors/main.cpp) | | Medium | 2024/06/12 | [x] | [ ] |
| 274 | [H-Index](https://leetcode.com/problems/h-index/description/)| [C++](./Sorting/274.%20H-Index/main.cpp) | | Medium | 2024/06/29 | [x] | [ ] |
| 148 | [Sort List](https://leetcode.com/problems/sort-list/description/)| [C++](./Sorting/148.%20Sort%20List/main.cpp) | | Medium | 2024/07/13 | [x] | [ ] |

## Binary Search

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 704 | [Binary Search](https://leetcode.com/problems/binary-search/)| [Iterative](./Binary%20Search/704.%20Binary%20Search/iterative.cpp) [Recursive](./Binary%20Search/704.%20Binary%20Search/recursive.cpp)| [README](./Binary%20Search/704.%20Binary%20Search/README.md) [Note](./Binary%20Search/704.%20Binary%20Search/Note.pdf)| Easy | 2023/12/30 | [x] | [ ] |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)| [C++](./Binary%20Search/33.%20Search%20in%20Rotated%20Sorted%20Array/main.cpp)| [README](./Binary%20Search/33.%20Search%20in%20Rotated%20Sorted%20Array/README.md) [Note](./Binary%20Search/33.%20Search%20in%20Rotated%20Sorted%20Array/Note.pdf) | Medium | 2023/12/31 | [x] | [ ] |
| 287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)| [Sort and Binary Search](./Binary%20Search/287.%20Find%20the%20Duplicate%20Number/sort-and-binary-search.cpp) [Bit Sum](./Binary%20Search/287.%20Find%20the%20Duplicate%20Number/bit-sum.cpp)| [Note](./Binary%20Search/287.%20Find%20the%20Duplicate%20Number/Note.pdf) | Medium | 2024/01/01 | [x] | [ ] |
| 162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/)| [C++](./Binary%20Search/162.%20Find%20Peak%20Element/main.cpp) | [Note](./Binary%20Search/162.%20Find%20Peak%20Element/Note.pdf) | Medium | 2024/01/02 | [x] | [ ] |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)| [C++](./Binary%20Search/74.%20Search%20a%202D%20Matrix/main.cpp) | [Note](./Binary%20Search/74.%20Search%20a%202D%20Matrix/Note.pdf) | Medium | 2024/01/04 | [x] | [ ] |
| 744 | [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target)| [C++](./Binary%20Search/744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/main.cpp) | [Note](./Binary%20Search/744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/Note.pdf) | Easy | 2024/01/04 | [x] | [ ] |
| 1351 | [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)| [C++](./Binary%20Search/1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/main.cpp) | [Note](./Binary%20Search/1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/Note.pdf) | Easy | 2024/01/04 | [x] | [ ] |
| 34 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)| [C++](./Binary%20Search/34.%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array/main.cpp) | [Note](./Binary%20Search/34.%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array/Note.pdf) | Medium | 2024/01/05 | [x] | [ ] |
| 436 | [Find Right Interval](https://leetcode.com/problems/find-right-interval/)| [C++](./Binary%20Search/436.%20Find%20Right%20Interval/main.cpp) | [Note](./Binary%20Search/436.%20Find%20Right%20Interval/Note.pdf) | Medium | 2024/01/05 | [x] | [ ] |
| 981 | [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)| [C++](./Binary%20Search/981.%20Time%20Based%20Key-Value%20Store/main.cpp) | [Note](./Binary%20Search/981.%20Time%20Based%20Key-Value%20Store/Note.pdf) | Medium | 2024/01/06 | [x] | [ ] |
| 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)| [C++](./Binary%20Search/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/main.cpp) | | Medium | 2024/01/11 | [x] | [ ] |
| 154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)| [C++](./Binary%20Search/154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/main.cpp) | | Hard | 2024/01/11 | [x] | [ ] |
| 702 | [Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size)| [C++](./Binary%20Search/702.%20Search%20in%20a%20Sorted%20Array%20of%20Unknown%20Size/main.cpp) | | Medium | 2024/01/17 | [ x] | [ ] |
| 362 | [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/description/)| [C++](./Queue/362.%20Design%20Hit%20Counter/main.cpp) | | Medium | 2024/03/17 | [x] | [ ] |
| 633 | [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/)| [C++](./Binary%20Search/633.%20Sum%20of%20Square%20Numbers/main.cpp) | | Medium | 2024/06/17 | [x] | [ ] |

## [Two-Pointers](https://leetcode.com/tag/two-pointers/)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)| [C++](./Two.%20Pointers/88.%20Merge%20Sorted%20Array/main.cpp) | | Easy | 2024/01/06 | [x] | [ ] |
| 15 | [3Sum](https://leetcode.com/problems/3sum/)| [C++](./Two.%20Pointers/15.%203Sum/main.cpp) | | Medium | 2024/01/06 | [x] | [ ] |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/)| [C++](./Two.%20Pointers/1.%20Two%20Sum/main.cpp) | | Easy | 2024/01/07 | [x] | [ ] |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)| [C++](./Two.%20Pointers/11.%20Container$20With%20Most%20Water/main.cpp) | [Note](./Two.%20Pointers/11.%20Container$20With%20Most%20Water/Note.pdf) | Medium | 2024/01/07 | [x] | [ ] |
| 34 | [Next Permutation](https://leetcode.com/problems/next-permutation/)| [C++](./Two.%20Pointers/34.%20Next%20Permutation/main.cpp) | [Note](./Two.%20Pointers/34.%20Next%20Permutation/Note.pdf) | Medium | 2024/01/07 | [x] | [ ] |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [C++](./Two.%20Pointers/125.%20Valid%20Palindrome/main.cpp) | | Easy | 2024/07/03 | [x] | [ ] |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](./Two.%20Pointers/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/main.cpp) | | Easy | 2024/07/14 | [x] | [ ] |

## Sliding Window

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges/description/) | [C++](./Sliding%20Window/228.%20Summary%20Ranges/main.cpp) | | Easy | 2024/07/04 | [x] | [ ] |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/) | [C++](./Sliding%20Window/3.%20Longest%20Substring%20Without%20Repeating%20Characters/main.cpp) | | Medium | 2024/07/05 | [x] | [ ] |

## Bit Operation

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 1550 | [Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/description/)| [C++](./Bit%20Operation/1550.%20Three%20Consecutive%20Odds/main.cpp) | | Easy | 2024/07/01 | [ ] | [ ] |

## Backtracking

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)| [C++](./Backtracking/17.%20Letter%20Combinations%20of%20a%20Phone%20Number/main.cpp) | | Medium | 2024/07/13 | [x] | [ ] |

## Recursion

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Graph Algorithm

- Adjacency List Implementation: [main.cpp](./Graph/Implementations/Adjacency%20List/main.cpp)
- BFS Implementation [main.cpp](./Graph/Implementations/BFS/main.cpp)
- DFS Implementation [dfs-with-adjacency-matrix.cpp](./Graph/Implementations/DFS/dfs-with-adjacency-matrix.cpp)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)| [C++](./Graph/547.%20Number%20of%20Provinces/main.cpp) | | Medium | 2024/01/27 | [x] | [ ] |
| 261 | [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)| [C++](./Graph/261.%20Graph%20Valid%20Tree/main.cpp) | | Medium | 2024/01/27 | [x] | [ ] |
| 490 | [The Maze](https://leetcode.com/problems/the-maze/description/)| [C++](./Graph/490.%20The%20Maze/main.cpp) | | Medium | 2024/03/19 | [x] | [ ] |
| 802 | [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)| [C++](./Graph/802.%20Find%20Eventual%20Safe%20States/main.cpp) | | Medium | 2024/01/28 | [ ] | [ ] |
| 695 | [Max Area of Island](https://leetcode.com/problems/max-area-of-island/description/)| [C++](./Graph/695.%20Max%20Area%20of%20Island/main.cpp) | | Medium | 2024/06/13 | [x] | [ ] |
| 286 | [Walls and Gates](https://leetcode.com/problems/walls-and-gates/description/)| [C++](./Graph/286.%20Walls%20and%20Gates/main.cpp) | | Medium | 2024/06/13 | [x] | [ ] |
| 994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/)| [C++](./Graph/994.%20Rotting%20Oranges/main.cpp) | | Medium | 2024/06/13 | [x]  | [ ] |
| 2285 | [Maximum Total Importance of Roads](https://leetcode.com/problems/maximum-total-importance-of-roads/description/)| [C++](./Graph/2285.%20Maximum%20Total%20Importance%20of%20Roads/main.cpp) | | Medium | 2024/06/28 | [x]  | [ ] |
| 841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/description/)| [C++](./Graph/841.%20Keys%20and%20Rooms/main.cpp) | | Medium | 2024/07/06 | [x]  | [ ] |
| 1129 | [Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)| [C++](./Graph/1129.%20Shortest%20Path%20with%20Alternating%20Colors/main.cpp) | | Medium | 2024/07/06 | [x]  | [ ] |
| 997 | [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/description/)| [C++](./Graph/997.%20Find%20the%20Town%20Judge/main.cpp) | | Easy | 2024/07/06 | [x]  | [ ] |
| 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/description/)| [C++](./Graph/200.%20Number%20of%20Islands/main.cpp) | | Medium | 2024/07/09 | [x]  | [ ] |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)| [C++](./Graph/1926.%20Nearest%20Exit%20from%20Entrance%20in%20Maze/main.cpp) | | Medium | 2024/07/09 | [x]  | [ ] |
| 1557 | [Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)| [C++](./Graph/1557.%20Minimum%20Number%20of%20Vertices%20to%20Reach%20All%20Nodes/main.cpp) | | Medium | 2024/07/09 | [x]  | [ ] |
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/description/)| [C++](./Graph/399.%20Evaluate%20Division/main.cpp) | | Medium | 2024/07/13 | [x]  | [ ] |
| 733 | [Flood Fill](https://leetcode.com/problems/flood-fill/description/)| [C++](./Graph/733.%20Flood%20Fill/main.cpp) | | Medium | 2024/07/13 | [x]  | [ ] |
| 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/description/)| [C++](./Graph/207.%20Course%20Schedule/main.cpp) | | Medium | 2024/06/14 | [ ]  | [ ] |

## Greedy

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 948 | [Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/description/)| [C++](./Dynamic%20Programming/948.%20Bag%20of%20Tokens/main.cpp) | | Medium | 2024/03/04 | [x] | [ ] |
| 1564 | [Put Boxes Into the Warehouse I](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/description/)| [C++](./Greedy/1564.%20Put%20Boxes%20Into%20the%20Warehouse%20I/main.cpp) | | Medium | 2024/06/15 | [x] | [ ] |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/description/)| [C++](./Greedy/134.%20Gas%20Station/main.cpp) | | Medium | 2024/06/29 | [ ] | [ ] |
| 1580 | [Put Boxes Into the Warehouse II](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/description/)| [C++](./Greedy/1564.%20Put%20Boxes%20Into%20the%20Warehouse%20II/main.cpp) | | Medium | 2024/06/15 | [x] | [ ] |
| 135 | [Candy](https://leetcode.com/problems/candy/description/)| [C++](./Greedy/135.%20Candy/main.cpp) | | Hard | 2024/07/02 | [x] | [ ] |
| 1509 | [Minimum Difference Between Largest and Smallest Value in Three Moves](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)| [C++](./Greedy/1509.%20Minimum%20Difference%20Between%20Largest%20and%20Smallest%20Value%20in%20Three%20Moves/main.cpp) | | Medium | 2024/07/02 | [x] | [ ] |
| 452 | [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)| [C++](./Greedy/452.%20Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons/main.cpp) | | Medium | 2024/07/10 | [x] | [ ] |
| 1717 | [Maximum Split of Positive Even Integers](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)| [C++](./Greedy/1717.%20Maximum%20Split%20of%20Positive%20Even%20Integers/main.cpp) | | Medium | 2024/07/12 | [x] | [ ] |
| 68 | [Text Justification](https://leetcode.com/problems/text-justification/description/)| [C++](./Greedy/68.%20Text%20Justification/main.cpp) | | Hard | 2024/07/16 | [x] | [ ] |

## Dynamic Programming

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs)| [C++](./Dynamic%20Programming/70.%20Climbing%20Stairs/main.cpp) | | Easy | 2024/01/04 | [x] | [ ] |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number)| [C++](./Dynamic%20Programming/1137.%20N-th%20Tribonacci%20Number/main.cpp) | | Easy | 2024/01/05 | [x] | [ ] |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)| [C++](./Dynamic%20Programming/746.%20Min%20Cost%20Climbing%20Stairs/main.cpp) | | Easy | 2024/01/05 | [x] | [ ] |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/)| [C++](./Dynamic%20Programming/198.%20House%20Robber/main.cpp) | | Medium | 2024/01/05 | [x] | [ ] |
| 740 | [Delete and Earn](https://leetcode.com/problems/delete-and-earn/)| [C++](./Dynamic%20Programming/740.%20Delete%20and%20Earn/main.cpp) | [Note](./Dynamic%20Programming/740.%20Delete%20and%20Earn/Note.pdf) | Medium | 2024/01/06 | [x] | [ ] |
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/)| [C++](./Dynamic%20Programming/62.%20Unique%20Paths/main.cpp) | [Note](./Dynamic%20Programming/62.%20Unique%20Paths/Note.pdf) | Medium | 2024/01/06 | [x] | [ ] |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)| [C++](./Dynamic%20Programming/64.%20Minimum%20Path%20Sum/main.cpp) | | Medium | 2024/01/06 | [x] | [ ] |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)| [C++](./Dynamic%20Programming/63.%20Unique%20Paths%20II/main.cpp) | | Medium | 2024/01/11 | [x] | [ ] |
| 120 | [Triangle](https://leetcode.com/problems/triangle/)| [C++](./Dynamic%20Programming/120.%20Triangle/main.cpp) | | Medium | 2024/01/13 | [x] | [ ] |
| 931 | [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/)| [C++](./Dynamic%20Programming/931.%20Minimum%20Falling%20Path%20Sum/main.cpp) | | Medium | 2024/01/16 | [x] | [ ] |
| 221 | [Maximal Square](https://leetcode.com/problems/maximal-square/)| [C++](./Dynamic%20Programming/221.%20Maximal%20Square/main.cpp) | | Medium | 2024/01/17 | [x] | [ ] |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)| [C++](./Dynamic%20Programming/5.%20Longest%20Palindromic%20Substring/main.cpp) | [Note](./Dynamic%20Programming/5.%20Longest%20Palindromic%20Substring/Note.pdf) | Medium | 2024/01/17 | [x] | [ ] |
| 139 | [Word Break](https://leetcode.com/problems/word-break/)| [C++](./Dynamic%20Programming/139.%20Word%20Break/main.cpp) | [Note](./Dynamic%20Programming/139.%20Word%20Break/Note.pdf) | Medium | 2024/01/18 | [x] | [ ] |
| 516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)| [C++](./Dynamic%20Programming/516.%20Longest%20Palindromic%20Subsequence/main.cpp) | | Medium | 2024/01/18 | [x] | [ ] |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/)| [C++](./Dynamic%20Programming/72.%20Edit%20Distance/main.cpp) | | Medium | 2024/01/22 | [x] | [ ] |
| 712 | [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)| [C++](./Dynamic%20Programming/712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/main.cpp) | | Medium | 2024/01/25 | [x] | [ ] |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)| [C++](./Dynamic%20Programming/300.%20Longest%20Increasing%20Subsequence/main.cpp) | | Medium | 2024/01/25 | [x] | [ ] |
| 673 | [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)| [C++](./Dynamic%20Programming/673.%20Number%20of%20Longest%20Increasing%20Subsequence/main.cpp) | | Medium | 2024/01/25 | [x] | [ ] |
| 646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)| [C++](./Dynamic%20Programming/646.%20Maximum%20Length%20of%20Pair%20Chain/main.cpp) | | Medium | 2024/01/25 | [x] | [ ] |
| 1218 | [Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/)| [C++](./Dynamic%20Programming/1218.%20Longest%20Arithmetic%20Subsequence%20of%20Given%20Difference/main.cpp) | | Medium | 2024/01/26 | [x] | [ ] |
| 416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/)| [C++](./Dynamic%20Programming/416.%20Partition%20Equal%20Subset%20Sum/main.cpp) | | Medium | 2024/06/13 | [x] | [ ] |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/description/)| [C++](./Dynamic%20Programming/55.%20Jump%20Game/main.cpp) | | Medium | 2024/06/29 | [x] | [ ] |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/description/)| [C++](./Dynamic%20Programming/45.%20Jump%20Game%20II/main.cpp) | | Medium | 2024/07/02 | [x] | [ ] |
| 2582 | [Pass the Pillow](https://leetcode.com/problems/pass-the-pillow/) | [C++](./Math/2582.%20Pass%20the%20Pillow/main.cpp) | | Easy | 2024/07/07 | [x] | [ ] |
| 1823 | [Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/) | [C++](./Math/1823.%20Find%20the%20Winner%20of%20the%20Circular%20Game/main.cpp) | | Medium | 2024/07/08 | [x] | [ ] |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [C++](./Dynamic%20Programming/53.%20Maximum%20Subarray/main.cpp) | | Medium | 2024/07/13 | [x] | [ ] |

# Divide and Conquer

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 427 | [Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/) | [C++](./Divide%20and%20Conquer/427.%20Construct%20Quad%20Tree/main.cpp) | | Medium | 2024/07/13 | [x] | [ ] |

# Reference：

- [Leetcode刷題學習筆記--心得統整 - HackMD](https://hackmd.io/@meyr543/r1skFcvgY)
- [0到100的軟體工程師面試之路 :: 2022 iThome 鐵人賽](https://ithelp.ithome.com.tw/users/20152262/ironman/5615)
- [演算法學習之-Leetcode-破關總指南（一）. 新手村與基本功訓練 | by Arthur Lin | AppWorks School | Medium](https://medium.com/appworks-school/%E6%BC%94%E7%AE%97%E6%B3%95%E5%AD%B8%E7%BF%92%E4%B9%8B-leetcode-%E7%A0%B4%E9%97%9C%E7%B8%BD%E6%8C%87%E5%8D%97-%E4%B8%80-873b3fb65152)
- [Re: [請益] Leetcode刷一輪到能面試的程度要多久？ - 看板Soft_Job - PTT網頁版 (pttweb.cc)](https://www.pttweb.cc/bbs/Soft_Job/M.1545435337.A.B03)
- [Re: [討論] 軟體工作真的有需要刷題嗎? - 看板 Soft_Job - 批踢踢實業坊 (ptt.cc)](https://www.ptt.cc/bbs/Soft_Job/M.1629026770.A.B4E.html)
- [思而不學則殆 站在大神的肩膀上](https://ithelp.ithome.com.tw/m/articles/10298003)
- [coding interview university](https://github.com/chuangellow/coding-interview-university)
- [Blind 75](https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions)
- [Grind 169](https://www.techinterviewhandbook.org/grind75?weeks=15&hours=40)
- [How to practice for 2200+ rating in LC](https://leetcode.com/discuss/study-guide/1965086/How-to-practice-for-2200%2B-rating-in-LC)
- [從面試官角度來看程式面試：兩大能力與七個階段](https://holyisland.blog/coding-interview-steps/)