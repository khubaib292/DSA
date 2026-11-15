

\# Two Sum II – Input Array Is Sorted



\- \*\*Platform:\*\* LeetCode

\- \*\*Problem Number:\*\* 167

\- \*\*Difficulty:\*\* Medium

\- \*\*Pattern:\*\* Two Pointers

\- \*\*Approach:\*\* Opposite Direction Pointers

\- \*\*Language:\*\* C++



\## 1. Problem Understanding



Given a 1-indexed array of integers sorted in non-decreasing

order, find two numbers whose sum equals the target.



Return their indices using 1-based indexing.



\## 2. Initial Intuition



Since the array is already sorted, we can use two pointers

instead of checking every possible pair.



I initialized:

\- Left pointer at the beginning.

\- Right pointer at the end.



The sum of these two elements determines which pointer

should move.



\## 3. Approach



1\. Initialize `l = 0` and `r = n - 1`.

2\. Calculate the sum of the elements at both pointers.

3\. If the sum equals the target, return their 1-based indices.

4\. If the sum is smaller than the target, increment `l`.

5\. If the sum is greater than the target, decrement `r`.

6\. Continue until the pointers meet.



\## 4. Why Does This Work?



The array is sorted.



\- If the sum is too small, moving the right pointer left

&#x20; would only make the sum smaller. Therefore, move left

&#x20; forward to increase the sum.

\- If the sum is too large, moving the left pointer right

&#x20; would only make the sum larger. Therefore, move right

&#x20; backward to decrease the sum.



This eliminates unnecessary pairs.



\## 5. Dry Run



Input:



```text

numbers = \[2, 7, 11, 15]

target = 9

```



| Step | Left | Right | Sum | Action |

|---|---:|---:|---:|---|

| 1 | 2 | 15 | 17 | Move right |

| 2 | 2 | 11 | 13 | Move right |

| 3 | 2 | 7 | 9 | Found |



Output:



```text

\[1, 2]

```



\## 6. Edge Cases



| Case | Expected behavior |

|---|---|

| Minimum valid array size | Check the only possible pair |

| Pair at array boundaries | Both pointers find the pair |

| Negative numbers | Comparison logic still works |

| Duplicate values | Different indices can be returned |

| No valid pair | Return empty vector defensively |



The original problem guarantees exactly one solution.



\## 7. Complexity Analysis



\*\*Time Complexity: O(n)\*\*



Each pointer moves in only one direction.

At most n - 1 pointer movements are needed.



\*\*Auxiliary Space Complexity: O(1)\*\*



Only a constant number of variables are used.

The returned vector is excluded from auxiliary space.



\## 8. Key Learnings



\- Sorted arrays enable efficient pointer-based searching.

\- Pointer movement must be justified by sorted order.

\- 1-based indexing must be handled when returning indices.

\- Two Pointers can reduce O(n²) brute force to O(n).



\## 9. Source



\[LeetCode – Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)



