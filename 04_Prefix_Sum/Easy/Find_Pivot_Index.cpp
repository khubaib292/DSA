
/*
Problem: Find Pivot Index
LeetCode: 724
Difficulty: Easy
Pattern: Prefix Sum

Problem Understanding:
Find an index where the sum of elements to its left
equals the sum of elements to its right.

Initial Intuition:
Calculate the total sum first and maintain a running
left sum while traversing the array.

Approach:
Right Sum = Total Sum - Left Sum - Current Element

If Left Sum == Right Sum, return the current index.
Otherwise, add the current element to Left Sum.

Why It Works:
At every index, we can calculate the right sum
using the total sum and the left sum.

Dry Run:
Input: [1, 7, 3, 6, 5, 6]
At index 3:
Left Sum = 11
Right Sum = 11
Answer = 3

Complexity:
Time: O(n)
Auxiliary Space: O(1)

Key Learning:
Prefix Sum avoids repeatedly calculating subarray sums.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int ts = 0, ls = 0;

        for (int i = 0; i < n; i++) {
            ts += nums[i];
        }

        for (int i = 0; i < n; i++) {
            int rs = ts - ls - nums[i];

            if (ls == rs) {
                return i;
            }

            ls += nums[i];
        }

        return -1;
    }
};
