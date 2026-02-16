# Linear and Binary Search Lab

## Question 1

For the array:

[2, 4, 6, 8, 10, 12, 13]

If we use **linear search** to find the number 8, we check each value from left to right:

1. 2 ≠ 8  
2. 4 ≠ 8  
3. 6 ≠ 8  
4. 8 = 8  

So it takes **4 comparisons** to find the value.

Answer: **4 steps**

---

## Question 2

Using **binary search** on the same array:

Since the array is already sorted, we check the middle element first.

Middle index = 3 → value = 8  

We find the value immediately.

Answer: **1 step**

---

## Question 3

For an array of size 100,000, binary search repeatedly cuts the search space in half.

The maximum number of comparisons is:

⌊log₂(100000)⌋ + 1

log₂(100000) is a little over 16, so the maximum number of comparisons is **17**.

Answer: **17 comparisons**

---

## Question 4 – Implementation and Analysis

### Program Overview

In my program, I created a sorted vector with 100,000 elements (0 to 99,999).

I implemented:
- Linear search
- Binary search

Both functions count how many comparisons are performed during the search so we can clearly see the difference in performance.

### Observations

When searching for a value near the beginning of the array, linear search performs very few comparisons.  
When searching near the end (or if the value is not found), linear search may perform up to 100,000 comparisons.

Binary search, on the other hand, consistently performs around 17 comparisons in the worst case, even for 100,000 elements.

### Complexity Explanation

Linear search checks elements one by one.  
In the worst case, it examines all N elements.  

Time Complexity: **O(N)**

Binary search halves the search range in each iteration.  
The number of times we can halve N until we reach 1 element is log₂(N).

Time Complexity: **O(log N)**

This explains why binary search is significantly faster for large sorted datasets.

---

## Question 5 – Randomized Search

### Pseudocode

Create a vector containing indices from 0 to N-1  
Randomly shuffle the indices  
Loop through the shuffled indices:  
    Compare the element at that index with the key  
    If found, return the index  
If all elements are checked and not found, return -1  

Each element is examined at most once.

### Time Complexity

Best case: O(1)  
(If the key happens to be checked first)

Average case: O(N)  
(On average, about half the elements are checked)

Worst case: O(N)  
(If the key is last or not present)

### Comparison with Other Search Algorithms

Linear Search:
- Time complexity: O(N)
- Works on unsorted data
- Very simple to implement

Binary Search:
- Time complexity: O(log N)
- Requires the data to be sorted
- Much more efficient for large datasets

Randomized Search:
- Time complexity: O(N)
- Does not require sorted data
- Adds extra overhead due to randomization
- Does not improve performance compared to linear search

Overall, binary search is the most efficient option when the data is sorted. Linear search is simpler and works for any dataset. Randomized search does not provide a time complexity advantage but demonstrates a different search strategy.

