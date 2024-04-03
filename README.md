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

- [Sorting](#sorting)
- [Two-Pointers](#two-pointers)
- [Sliding window](#sliding-window)
- [Bit operation](#bit-operation)
- [Recursion](#recursion)
- [Greedy](#greedy)
- [Dynamic Programming](#dynamic-programming)
- [Graph Algorithm](#graph-algorithm)

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

## Linked List

- Singly Linked List Implementation: [C++](./Linked%20List/Implementations/Singly%20Linked%20List)
- Circular Linked List Implementation: [C++](./Linked%20List/Implementations/Circular%20Linked%20List/)
- Double Linked List Implementation: [C++](./Linked%20List/Implementations/Double%20Linked%20List/)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 2095 | [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)| [C](./Linked%20List/2095.%20Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/main.c) | | Medium | 2024/02/28 | [x] | [ ] |
| 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)| [C](./Linked%20List/82.%20Remove%20Duplicates%20from%20Sorted%20List%20II/main.c) | | Medium | 2024/02/28 | [x] | [ ] |
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)| [C](./Linked%20List/25.%20Reverse%20Nodes%20in%20k-Group/main.c) | | Hard | 2024/02/29 | [x] | [ ] |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/)| [C++](./Linked%20List/) | | Medium | 2024/04/03 | [x] | [ ] |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)| [C](./Linked%20List/23.%20Merge%20k%20Sorted%20Lists/main.c) | | Hard | 2024/03/01 | [ ] | [ ] |

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Set

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## String

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

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

## [Two-Pointers](https://leetcode.com/tag/two-pointers/)

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)| [C++](./Two.%20Pointers/88.%20Merge%20Sorted%20Array/main.cpp) | | Easy | 2024/01/06 | [x] | [ ] |
| 15 | [3Sum](https://leetcode.com/problems/3sum/)| [C++](./Two.%20Pointers/15.%203Sum/main.cpp) | | Medium | 2024/01/06 | [x] | [ ] |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/)| [C++](./Two.%20Pointers/1.%20Two%20Sum/main.cpp) | | Easy | 2024/01/07 | [x] | [ ] |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)| [C++](./Two.%20Pointers/11.%20Container$20With%20Most%20Water/main.cpp) | [Note](./Two.%20Pointers/11.%20Container$20With%20Most%20Water/Note.pdf) | Medium | 2024/01/07 | [x] | [ ] |
| 34 | [Next Permutation](https://leetcode.com/problems/next-permutation/)| [C++](./Two.%20Pointers/34.%20Next%20Permutation/main.cpp) | [Note](./Two.%20Pointers/34.%20Next%20Permutation/Note.pdf) | Medium | 2024/01/07 | [x] | [ ] |

## Sliding Window

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Bit Operation

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

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

## Greedy

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |
| 948 | [Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/description/)| [C++](./Dynamic%20Programming/948.%20Bag%20of%20Tokens/main.cpp) | | Medium | 2024/03/04 | [x] | [ ] |

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

# Reference：

- [Leetcode刷題學習筆記--心得統整 - HackMD](https://hackmd.io/@meyr543/r1skFcvgY)
- [0到100的軟體工程師面試之路 :: 2022 iThome 鐵人賽](https://ithelp.ithome.com.tw/users/20152262/ironman/5615)
- [演算法學習之-Leetcode-破關總指南（一）. 新手村與基本功訓練 | by Arthur Lin | AppWorks School | Medium](https://medium.com/appworks-school/%E6%BC%94%E7%AE%97%E6%B3%95%E5%AD%B8%E7%BF%92%E4%B9%8B-leetcode-%E7%A0%B4%E9%97%9C%E7%B8%BD%E6%8C%87%E5%8D%97-%E4%B8%80-873b3fb65152)
- [Re: [請益] Leetcode刷一輪到能面試的程度要多久？ - 看板Soft_Job - PTT網頁版 (pttweb.cc)](https://www.pttweb.cc/bbs/Soft_Job/M.1545435337.A.B03)
- [Re: [討論] 軟體工作真的有需要刷題嗎? - 看板 Soft_Job - 批踢踢實業坊 (ptt.cc)](https://www.ptt.cc/bbs/Soft_Job/M.1629026770.A.B4E.html)
- [思而不學則殆 站在大神的肩膀上](https://ithelp.ithome.com.tw/m/articles/10298003)
- [coding interview university](https://github.com/chuangellow/coding-interview-university)