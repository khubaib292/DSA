
/*
Problem: Squares of a Sorted Array
LeetCode: 977
Topic: Arrays
Pattern: Two Pointers
Difficulty: Easy

Problem Understanding:
Given a sorted array containing negative and positive integers,
return a new array containing the squares of all elements
in sorted (non-decreasing) order.

Initial Intuition:
Squaring negative numbers can change their relative order.
For example, -5 becomes 25.
Therefore, directly squaring the elements does not guarantee
a sorted result.

Approach: Two Pointers
1. Initialize left pointer at index 0.
2. Initialize right pointer at the last index.
3. Compare the squares of both endpoint elements.
4. Place the larger square at the last available position
   in the result array.
5. Move the pointer from which the larger square came.
6. Move the result position backward.
7. Continue until left crosses right.

Why This Works:
Since the input array is sorted, the element with the
largest absolute value must be at one of its two ends.
Comparing both ends allows us to fill the result array
from largest square to smallest square.

Dry Run:
Input:  [-4, -1, 0, 3, 10]
Output: [0, 1, 9, 16, 100]

Edge Cases:
- Empty array
- Single element
- All negative elements
- All positive elements
- Duplicate values
- Array containing zero

Time Complexity: O(n)
Space Complexity: O(n) for the result array
Auxiliary Space: O(1), excluding the result array

Key Learning:
Two pointers can efficiently solve problems involving
sorted arrays by comparing values at both ends.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n - 1, k = n - 1;

        while (l <= r) {
            if (nums[l] * nums[l] > nums[r] * nums[r]) {
                ans[k] = nums[l] * nums[l];
                l++;
            } else {
                ans[k] = nums[r] * nums[r];
                r--;
            }
            k--;
        }

        return ans;
    }
};
