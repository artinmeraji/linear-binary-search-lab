# Linear and Binary Search Lab

## Question 1
Array: [2, 4, 6, 8, 10, 12, 13]

Using linear search to find 8:
1) 2 ≠ 8  
2) 4 ≠ 8  
3) 6 ≠ 8  
4) 8 = 8  

**Answer: 4 comparisons**

---

## Question 2
Using binary search on the same sorted array:

Middle index = 3 → value = 8, so it is found immediately.

**Answer: 1 comparison**

---

## Question 3
Binary search worst-case comparisons are about:

⌊log₂(N)⌋ + 1

For N = 100,000, log₂(100,000) is a little over 16, so the max comparisons is:

⌊16.x⌋ + 1 = **17**

**Answer: 17 comparisons**

---

## Question 4 – Implementation + Big-O Analysis

### What my program does
- Builds a sorted vector of 100,000 integers (0 to 99,999)
- Runs linear search and binary search for a user-entered key
- Counts the number of comparisons (steps) each algorithm performs

### What I observed
- Linear search depends on where the key is:
  - Near the start: small number of comparisons
  - Near the end or not found: can reach 100,000 comparisons
- Binary search stays small even for large N, because it keeps cutting the search range in half (about ~17 comparisons worst case for 100,000)

### Why (Big-O)
**Linear Search:** checks elements one-by-one. Worst case examines all N elements → **O(N)**  
**Binary Search:** halves the search space each step. Number of steps grows like log₂(N) → **O(log N)**

---

## Question 5 – Randomized Search (No Repetition)

### Pseudocode idea
- Create a list of indices 0..N-1
- Shuffle the indices randomly
- Visit elements in that shuffled order
- Stop when the key is found (each element checked at most once)

### Time Complexity
- Best case: **O(1)** (key happens to be checked first)
- Average case: **O(N)** (expected around N/2 checks)
- Worst case: **O(N)** (key is last or not in the dataset)

### Comparison (Randomized vs Linear vs Binary)
- **Linear Search**
  - Time: O(N)
  - Works on unsorted data
  - Very low overhead and simple

- **Binary Search**
  - Time: O(log N)
  - Requires sorted data
  - Most efficient for large ordered datasets

- **Randomized Search**
  - Time: O(N)
  - Does not require sorting
  - More overhead than linear search (shuffling + random order)
  - No Big-O advantage over linear search, mainly useful as an alternative strategy, not an optimization

