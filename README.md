# LeetCode Practice Record

This repository contains my solutions and explanations for various LeetCode problems. 

The problems are organized into directories based on the main technique or data structure needed to solve them.

## Table of Contents

### Data structure

- [Array](#array)
- [Linked List](#linked-list)
- [Hash Table](#hash-table)
- [String](#string)
- [Stack](#stack)
- [Queue](#queue)
- [Binary Tree](#binary-tree)
- [Monotonic Queue](#monotonic-queue)

### Algorithm

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

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Linked List

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Hash Table

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## String

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Stack

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Queue

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Binary Tree

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Monotonic Queue

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |


# 演算法策略

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
| 154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)| [C++](./Binary%20Search/154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/main.cpp) | [Note](./Binary%20Search/154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/Note.pdf) | Hard | 2024/01/11 | [x] | [ ] |

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

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

## Greedy

| # | Title | Solution | Note | Difficulty | Date | Done | Think Again |
|---| ----- | -------- | -------- | ---------- | ---------- | --- | --- |

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

# Reference：

- [Leetcode刷題學習筆記--心得統整 - HackMD](https://hackmd.io/@meyr543/r1skFcvgY)
- [0到100的軟體工程師面試之路 :: 2022 iThome 鐵人賽](https://ithelp.ithome.com.tw/users/20152262/ironman/5615)
- [演算法學習之-Leetcode-破關總指南（一）. 新手村與基本功訓練 | by Arthur Lin | AppWorks School | Medium](https://medium.com/appworks-school/%E6%BC%94%E7%AE%97%E6%B3%95%E5%AD%B8%E7%BF%92%E4%B9%8B-leetcode-%E7%A0%B4%E9%97%9C%E7%B8%BD%E6%8C%87%E5%8D%97-%E4%B8%80-873b3fb65152)
- [Re: [請益] Leetcode刷一輪到能面試的程度要多久？ - 看板Soft_Job - PTT網頁版 (pttweb.cc)](https://www.pttweb.cc/bbs/Soft_Job/M.1545435337.A.B03)
- [Re: [討論] 軟體工作真的有需要刷題嗎? - 看板 Soft_Job - 批踢踢實業坊 (ptt.cc)](https://www.ptt.cc/bbs/Soft_Job/M.1629026770.A.B4E.html)
- [coding interview university](https://github.com/chuangellow/coding-interview-university)