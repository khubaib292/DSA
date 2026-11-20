
/*
Problem: Running Sum of 1D Array
LeetCode: 1480
Workbook: Question #29
Pattern: Prefix Sum
Difficulty: Easy

Problem Understanding:
Given an integer array, calculate the running sum.
Each position contains the sum of all elements
from index 0 up to the current index.

Initial Intuition:
The current running sum can be calculated by
adding the current element to the previous prefix sum.

Approach: In-Place Prefix Sum
1. Start from index 1.
2. Add the previous updated element to the current element.
3. Continue until the last element.
4. Return the modified array.

Why It Works:
After updating nums[i], it stores the sum of all
elements from index 0 to i.

Dry Run:
Input:  [1, 2, 3, 4, 5]
Step 1: [1, 3, 3, 4, 5]
Step 2: [1, 3, 6, 4, 5]
Step 3: [1, 3, 6, 10, 5]
Step 4: [1, 3, 6, 10, 15]

Output: [1, 3, 6, 10, 15]

Edge Cases:
- Single-element array
- Array containing zeros
- Array containing negative values

Complexity Analysis:
Time Complexity: O(n)
Auxiliary Space: O(1)

Key Learning:
In-place prefix sum avoids creating an additional array.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};
