# Note on 704. Binary Search

# Key Point

When we're implementing the binary search, it's common to have some bugs when dealing with boundary conditions.

Since there are several decisions when we need to make during the implementation:

1. Do I use left or right mid?
2. Do I use < or <= , > or >=?
3. How much do I shrink the boundary? is it mid or mid - 1 or even mid + 1 ?

Therefore, we need to be careful about the following things during the implementation:

- Include ALL possible answers when initializing lo & hi
- Don't overflow the mid calculation
- Shrink boundary using a logic that will exclude mid
- Avoid infinity loop by picking the correct mid and shrinking logic
- Always think of the case when there are 2 elements left

# Reference

- [binary-search-101](https://leetcode.com/problems/binary-search/solutions/423162/binary-search-101/)