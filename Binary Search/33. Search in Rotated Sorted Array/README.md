# Note on 33. Search in Rotated Sorted Array

# Key Point

Binary search requires a sorted array to function correctly. 

Let's illustrate this with an example. Suppose we have a sorted array ```nums = [0, 1, 2, 3, 4, 5, 6]``` and our target is ```2```. 

In a binary search, if we find that the middle element is greater than the target (i.e., ```nums[mid] > target```), we can confidently ignore the second half of the array. 

In this case, the sub-array ```[4, 5, 6]``` can be disregarded, streamlining our search.

However, if the array is not sorted, like in ```nums = [0, 1, 5, 3, 4, 2, 6]```, the logic of binary search breaks down. 

Here, even if ```nums[mid] > target```, the target value 2 might still exist in the latter part of the array, as seen in the sub-array ```[4, 2, 6]```. 

In such scenarios, both halves of the array need to be considered (```[0, 1, 5]``` and ```[4, 2, 6]```), which effectively nullifies the efficiency of binary search.

 Hence, sorting the array is a prerequisite for applying binary search effectively.