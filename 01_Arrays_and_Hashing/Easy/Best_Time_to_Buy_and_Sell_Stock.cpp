
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Best Time to Buy and Sell Stock
LeetCode: 121
Difficulty: Easy
Pattern: Greedy / One-Pass Minimum Tracking

1. Problem Understanding:
   Given an array of stock prices, find the maximum profit
   by buying on one day and selling on a later day.
   If no profit is possible, return 0.

2. Initial Intuition:
   We need to buy at the lowest price seen so far
   and sell at a later day with a higher price.

3. Approach:
   - Initialize min_price with INT_MAX.
   - Initialize max_profit with 0.
   - Traverse the prices array.
   - Calculate today's profit using the previous minimum price.
   - Update max_profit if today's profit is greater.
   - Update min_price for future transactions.

4. Why This Works:
   We always calculate profit using a buying price
   from an earlier day, maintaining the required order.

5. Dry Run:
   Input: [7, 2, 5, 1, 6, 4]

   Day 0: Price = 7, min_price = 7, profit = 0
   Day 1: Price = 2, min_price = 2, profit = 0
   Day 2: Price = 5, min_price = 2, profit = 3
   Day 3: Price = 1, min_price = 1, profit = 0
   Day 4: Price = 6, min_price = 1, profit = 5
   Day 5: Price = 4, min_price = 1, profit = 3

   Maximum Profit = 5

6. Edge Cases:
   - Prices are continuously decreasing.
   - Only one stock price is given.
   - All prices are equal.
   - Maximum profit occurs on the final day.

7. Complexity Analysis:
   Time Complexity: O(n) - One traversal.
   Auxiliary Space: O(1) - Only two variables.

8. Key Learning:
   Track the minimum price so far and calculate
   the best possible profit at every day.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {

            max_profit = max(max_profit,
                             prices[i] - min_price);

            min_price = min(min_price, prices[i]);
        }

        return max_profit;
    }
};
