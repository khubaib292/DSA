
#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem        : Move Zeroes
Platform       : LeetCode
Problem No.    : 283
Difficulty     : Easy
Pattern        : Two Pointers
Approach       : Two Pointers with Swapping
Problem Link   : https://leetcode.com/problems/move-zeroes/
========================================================

1. PROBLEM UNDERSTANDING
-----------------------
Move all zeroes in the array to the end while maintaining
the relative order of all non-zero elements.

The operation must be performed in-place.

2. INITIAL INTUITION
--------------------
We need to separate non-zero elements from zeroes.

Instead of creating another array, we can use two pointers
to rearrange the elements in the original array.

3. APPROACH AND WHY IT WORKS
----------------------------
- z (slow pointer): Tracks the next position where a
  non-zero element should be placed.

- nz (fast pointer): Traverses the entire array.

- If nums[nz] is zero:
      Increment nz only.

- If nums[nz] is non-zero:
      Swap nums[nz] with nums[z].
      Increment both z and nz.

WHY IT WORKS:
The fast pointer scans from left to right, so non-zero
elements are placed in their original relative order.

Swapping preserves the displaced zero instead of
overwriting it.

4. DRY RUN
----------
Input: [0, 1, 0, 3, 12]

Initial:
z = 0, nz = 0

Step 1: nums[nz] = 0
        Increment nz.

Step 2: nums[nz] = 1
        Swap nums[0] and nums[1].
        Array: [1, 0, 0, 3, 12]

Step 3: nums[nz] = 0
        Increment nz.

Step 4: nums[nz] = 3
        Swap nums[1] and nums[3].
        Array: [1, 3, 0, 0, 12]

Step 5: nums[nz] = 12
        Swap nums[2] and nums[4].
        Array: [1, 3, 12, 0, 0]

Output: [1, 3, 12, 0, 0]

5. EDGE CASES
-------------
- Empty array.
- Array containing only zeroes.
- Array containing no zeroes.
- Single-element array.
- Zeroes at the beginning or end.
- Multiple consecutive zeroes.

6. COMPLEXITY ANALYSIS
----------------------
Time Complexity       : O(n)
Auxiliary Space       : O(1)

Each element is visited once, and rearrangement happens
directly inside the original array.

7. KEY LEARNINGS
----------------
- Understanding the slow and fast pointer technique.
- Using swapping to rearrange elements in-place.
- Maintaining relative order of non-zero elements.
- Achieving O(n) time and O(1) auxiliary space.

========================================================
*/

// Implementation

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if (n == 0 || n == 1) return;

        int z = 0, nz = 0;

        while (nz < n) {
            if (nums[nz] != 0) {
                swap(nums[nz], nums[z]);
                z++;
                nz++;
            } else {
                nz++;
            }
        }
    }
};
