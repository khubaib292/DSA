
/*
Problem: Maximum Average Subarray I
LeetCode: 643
Topic: Arrays
Pattern: Fixed Size Sliding Window
Difficulty: Easy

Problem Understanding:
Given an integer array nums and an integer k,
find the contiguous subarray of length k that has
the maximum average value.

Initial Intuition:
Recalculating the sum of every window from scratch
takes O(n * k) time.

Optimized Approach:
1. Calculate the sum of the first k elements.
2. Store it as the initial maximum sum.
3. Slide the window one position at a time:
   - Add the incoming element.
   - Remove the outgoing element.
4. Update the maximum sum.
5. Divide the maximum sum by k to get the average.

Why It Works:
Each new window differs from the previous window
by exactly one incoming and one outgoing element.
This avoids recalculating the entire window sum.

Example:
nums = {1, 12, -5, -6, 50, 3}, k = 4

Maximum-sum window = {12, -5, -6, 50}
Maximum sum = 51
Maximum average = 51 / 4 = 12.75

Edge Cases:
- k = 1
- k = nums.size()
- All elements are negative
- Array contains duplicate values

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int windowSum = 0;
        int maxSum = INT_MIN;

        // Calculate the first window sum
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        // Return the average without integer division
        return static_cast<double>(maxSum) / k;
    }
};

/*
Key Learnings:
- Fixed Size Sliding Window
- Reuse the previous window sum
- Add incoming and remove outgoing elements
- Avoid unnecessary recalculation
*/
