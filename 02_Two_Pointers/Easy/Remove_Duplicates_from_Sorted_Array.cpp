
/*
========================================================
Problem       : Remove Duplicates from Sorted Array
Platform      : LeetCode
Problem No.   : 26
Difficulty    : Easy
Pattern       : Two Pointers
Technique     : Slow and Fast Pointers

Problem Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

========================================================
1. PROBLEM UNDERSTANDING

Given a sorted integer array, remove duplicates in-place
so that each unique element appears only once.

Return the number of unique elements (k).

The first k elements must contain the unique elements
in their original relative order.

========================================================
2. INITIAL INTUITION

Since the array is sorted, duplicate elements appear
consecutively.

We can solve this using two pointers:

Slow Pointer (s):
Maintains the position of the last unique element.

Fast Pointer (f):
Traverses the array to find new unique elements.

========================================================
3. APPROACH

1. Handle the empty array.
2. Initialize s = 0 and f = 1.
3. Compare nums[f] with nums[s].
4. If both are equal:
   - Move f forward.
5. Otherwise:
   - Increment s.
   - Copy nums[f] into nums[s].
   - Increment f.
6. Return s + 1.

WHY DOES THIS WORK?

Because the array is sorted, duplicates are adjacent.

Whenever fast finds a new unique element, we place it
in the next available position using the slow pointer.

========================================================
4. DRY RUN

Input:
nums = [1, 1, 2, 2, 3]

| Step | s | f | Action |
|------|---|---|--------|
| 1    | 0 | 1 | Duplicate |
| 2    | 0 | 2 | New element |
| 3    | 1 | 3 | Duplicate |
| 4    | 1 | 4 | New element |

Output:
k = 3

First k elements:
[1, 2, 3]

========================================================
5. EDGE CASES

- Empty array: Return 0.
- Single element: Return 1.
- All elements are duplicates.
- No duplicate elements.
- Multiple consecutive duplicates.
- Negative and positive integers.

========================================================
6. COMPLEXITY ANALYSIS

Time Complexity: O(n)
Each element is processed at most once.

Auxiliary Space: O(1)
The array is modified in-place without extra storage.

========================================================
7. KEY LEARNINGS

- Sorted arrays simplify duplicate detection.
- Slow and fast pointers separate reading and writing.
- In-place modification avoids extra space.
- Correct pointer movement prevents unnecessary comparisons.

========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int s = 0, f = 1;

        while (f < n) {

            if (nums[f] == nums[s]) {
                f++;
            }
            else {
                s++;
                nums[s] = nums[f];
                f++;
            }
        }

        return s + 1;
    }
};
