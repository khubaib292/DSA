
/*
========================================================
Problem       : Two Sum II - Input Array Is Sorted
Platform      : LeetCode
Problem No.   : 167
Difficulty    : Medium
Pattern       : Two Pointers
Approach      : Opposite Direction Pointers

Problem Link:
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

========================================================
1. PROBLEM UNDERSTANDING

Given a sorted, 1-indexed array of integers, find two
numbers whose sum equals the given target.

Return their indices using 1-based indexing.

========================================================
2. INITIAL INTUITION

Since the array is sorted, checking every possible pair
using nested loops is unnecessary.

We can start with two pointers:
- Left pointer at the beginning.
- Right pointer at the end.

Based on their sum, we decide which pointer to move.

========================================================
3. APPROACH

1. Initialize left = 0 and right = n - 1.
2. Calculate numbers[left] + numbers[right].
3. If sum == target, return both indices + 1.
4. If sum < target, increment left.
5. If sum > target, decrement right.
6. Repeat until the pointers meet.

WHY DOES THIS WORK?

The array is sorted in non-decreasing order.

- If the sum is smaller than target, moving right
  backward would only decrease the sum. Therefore,
  move left forward.

- If the sum is greater than target, moving left
  forward would only increase the sum. Therefore,
  move right backward.

Each movement eliminates pairs that cannot be valid.

========================================================
4. DRY RUN

Input:
numbers = [2, 7, 11, 15]
target = 9

Step 1:
Left = 2, Right = 15
Sum = 17
17 > 9, move right backward.

Step 2:
Left = 2, Right = 11
Sum = 13
13 > 9, move right backward.

Step 3:
Left = 2, Right = 7
Sum = 9
Target found!

Output: [1, 2]

========================================================
5. EDGE CASES

- Minimum valid array size.
- Negative numbers.
- Duplicate values at different indices.
- Solution involving first and last elements.
- Solution involving adjacent elements.

The problem guarantees exactly one valid solution.

========================================================
6. COMPLEXITY ANALYSIS

Time Complexity       : O(n)
Auxiliary Space       : O(1)

Each pointer moves in only one direction.
At most n - 1 pointer movements are required.

========================================================
7. KEY LEARNINGS

- Sorted arrays enable efficient Two Pointer solutions.
- Pointer movement must be justified by sorted order.
- Understand 0-based versus 1-based indexing.
- Two Pointers reduces the brute-force O(n^2)
  approach to O(n).

========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
