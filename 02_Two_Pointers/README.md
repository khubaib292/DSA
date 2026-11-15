

\# 02. Two Pointers



\## Overview



The Two Pointers technique is an algorithmic approach that

uses two indices or references to traverse a data structure,

usually an array or string.



Instead of checking every possible combination, we use

two pointers to reduce unnecessary comparisons and improve

efficiency.



It is commonly used in problems involving:

\- Sorted arrays

\- Pair and triplet problems

\- Reversing arrays or strings

\- Removing duplicates

\- Palindrome checking

\- In-place modifications



\## 1. Core Intuition



The main idea is to maintain two pointers and move them

based on the conditions of the problem.



Rather than repeatedly examining the entire data structure,

we eliminate unnecessary search space by making intelligent

pointer movements.



\## 2. Types of Two Pointers



\### A. Opposite Direction Pointers



\- Start one pointer at the beginning.

\- Start another pointer at the end.

\- Move either pointer depending on the condition.

\- Continue until the pointers meet or cross.



Common applications:

\- Two Sum II

\- Container With Most Water

\- Valid Palindrome

\- Three Sum



\### B. Same Direction Pointers



\- Both pointers start near the beginning.

\- One pointer explores the elements.

\- Another pointer maintains a valid position.

\- Useful for modifying arrays in-place.



Common applications:

\- Remove Duplicates from Sorted Array

\- Remove Element

\- Move Zeroes



\### C. Fast and Slow Pointers



\- Two pointers move at different speeds.

\- Usually used to detect cycles or locate middle elements.

\- Often considered a specialized Two Pointers technique.



Common applications:

\- Linked List Cycle

\- Middle of the Linked List

\- Happy Number



\## 3. How to Identify Two Pointer Problems



Look for these characteristics:



1\. The problem involves an array, string or linked list.

2\. You need to find pairs or compare elements.

3\. The array is sorted or can be sorted.

4\. You need to modify an array in-place.

5\. You need to eliminate unnecessary comparisons.

6\. Brute force involves checking multiple combinations.



Important:

A sorted array is a useful indicator, but not every

Two Pointers problem requires sorting.



\## 4. Pointer Movement Logic



For an opposite-direction approach:



\- If the current condition is satisfied, return or process

&#x20; the current elements.

\- If the current value is smaller than required, move the

&#x20; pointer that can increase the value.

\- If the current value is greater than required, move the

&#x20; pointer that can decrease the value.



Pointer movement must always be justified by the

problem's properties.



\## 5. Complexity Analysis



Typical complexity:



| Approach | Time Complexity | Auxiliary Space |

|---|---|---|

| Opposite Direction | O(n) | O(1) |

| Same Direction | O(n) | O(1) |

| Fast and Slow | O(n) | O(1) |



These are common complexities, not guarantees for every

problem. Actual complexity depends on the implementation.



\## 6. Common Mistakes



\- Using incorrect loop conditions.

\- Accessing invalid array indices.

\- Moving the wrong pointer.

\- Forgetting whether indices are 0-based or 1-based.

\- Using the same element twice.

\- Ignoring duplicate values.

\- Sorting the array when original indices must be preserved.

\- Failing to consider empty or very small inputs.



\## 7. Problem-Solving Checklist



Before implementing a solution:



\- \[ ] Understand the input and output.

\- \[ ] Check whether the input is sorted.

\- \[ ] Identify the appropriate pointer strategy.

\- \[ ] Decide pointer initialization.

\- \[ ] Define when each pointer moves.

\- \[ ] Check boundary conditions.

\- \[ ] Analyze time complexity.

\- \[ ] Analyze auxiliary space complexity.

\- \[ ] Test edge cases.



\## 8. Practice Problems



\### Easy

\- Valid Palindrome

\- Remove Duplicates from Sorted Array

\- Move Zeroes



\### Medium

\- Two Sum II – Input Array Is Sorted

\- 3Sum

\- Container With Most Water

\- Sort Colors



\### Hard

\- Trapping Rain Water

\- Minimum Window Subsequence



\## 9. Key Takeaway



The Two Pointers technique helps reduce unnecessary

comparisons by intelligently moving two positions through

a data structure.



The most important skill is not simply knowing how to

initialize two pointers, but understanding why and when

each pointer should move.



