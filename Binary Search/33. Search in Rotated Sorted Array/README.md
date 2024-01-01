# Note on 33. Search in Rotated Sorted Array

# Key Point

## The Correctness of Binary Search

Binary search requires a sorted array to function correctly. 

Let's illustrate this with an example. Suppose we have a sorted array ```nums = [0, 1, 2, 3, 4, 5, 6]``` and our target is ```2```. 

In a binary search, if we find that the middle element is greater than the target (i.e., ```nums[mid] > target```), we can confidently ignore the second half of the array. 

In this case, the sub-array ```[4, 5, 6]``` can be disregarded, streamlining our search.

However, if the array is not sorted, like in ```nums = [0, 1, 5, 3, 4, 2, 6]```, the logic of binary search breaks down. 

Here, even if ```nums[mid] > target```, the target value 2 might still exist in the latter part of the array, as seen in the sub-array ```[4, 2, 6]```. 

In such scenarios, both halves of the array need to be considered (```[0, 1, 5]``` and ```[4, 2, 6]```), which effectively nullifies the efficiency of binary search.

 Hence, sorting the array is a prerequisite for applying binary search effectively.
 
## The Variation of Binary Search
 
Therefore, we need to find the pivot first to ensure the correctness of the binary search.

First, we can use some examples to find the properties of the pivot.

```nums = [0, 1, 2, 3, 4, 5, 6], pivot = 3``` => ```nums = [3, 4, 5, 6, 0, 1, 2]``` 

Here, we can define the pivot in the array after rotating as ```nums[3] = 6```.

We can observe that ```nums[3] > nums[4]```.

A simple brute force method is to traverse the entire array to find the ```nums[k] > nums[k+1]```.

However, it takes O(n) time when the pivot is ```1```.

We need to think up with a pivot definition which we can use the binary search on the array after rotating to find the pivot.

Can we apply the binary search based on the definition of pivot now?

When designing a binary search algorithm, we need to consider several things:

1. **What is the condition to shrink the subproblem?**
2. **When to terminate the search process?**

For example, in the original binary search algorithm.

1. We choose the left half array or right half array by comparing the middle element to the target.
2. We terminate the search process when we find the target or there is no element in the subproblem.