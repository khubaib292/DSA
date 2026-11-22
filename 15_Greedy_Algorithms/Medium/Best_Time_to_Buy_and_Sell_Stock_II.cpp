/*
Problem: Best Time to Buy and Sell Stock II
LeetCode: 122
Difficulty: Medium
Pattern: Greedy Algorithm
Topic: Array

Problem Understanding:
We can perform multiple stock transactions.
We must sell the current stock before buying again.
Our goal is to maximize total profit.

Initial Intuition:
Whenever the stock price increases from one day
to the next, we can capture that positive difference.

Approach:
1. Initialize profit = 0.
2. Traverse the array from index 1.
3. Calculate the difference between today's
   price and yesterday's price.
4. If the difference is positive, add it to profit.
5. Return the accumulated profit.

Why It Works:
Every positive consecutive price increase can
be captured through valid transactions.
Negative and zero differences do not contribute
to maximum profit.

Dry Run:
Prices = {7, 1, 5, 3, 6, 4}

1 -> 5 = +4
5 -> 3 = -2 (ignored)
3 -> 6 = +3

Total Profit = 4 + 3 = 7

Edge Cases:
- Continuously increasing prices.
- Continuously decreasing prices.
- All prices equal.
- Only one day's price.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];

            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};