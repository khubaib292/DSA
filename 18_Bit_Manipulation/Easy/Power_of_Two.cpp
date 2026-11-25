
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Power of Two
LeetCode: 231
Workbook: #453
Difficulty: Easy
Pattern: Bit Manipulation / Math

Problem Understanding:
Given an integer n, determine whether it is a power of 2.

Examples:
n = 1  -> true  (2^0)
n = 8  -> true  (2^3)
n = 12 -> false
n = 0  -> false
n = -4 -> false

==================================================
APPROACH 1: BRUTE FORCE - REPEATED DIVISION
==================================================

Initial Intuition:
A power of 2 can be repeatedly divided by 2
until we reach 1.

Steps:
1. If n <= 0, return false.
2. Divide n by 2 while it is even.
3. If the final value is 1, return true.
4. Otherwise, return false.

Dry Run:
n = 16

16 -> 8 -> 4 -> 2 -> 1

Final value = 1, so true.

n = 12

12 -> 6 -> 3

3 is not divisible by 2.
Final value = 3, so false.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        while (n % 2 == 0) {
            n = n / 2;
        }

        return n == 1;
    }
};

/*
==================================================
APPROACH 2: BETTER - REPEATED MULTIPLICATION
==================================================

Initial Intuition:
Generate powers of 2 starting from 1.
Compare each generated value with n.

Steps:
1. If n <= 0, return false.
2. Start with num = 1.
3. Multiply num by 2 while num < n.
4. If num == n, return true.
5. Otherwise, return false.

Dry Run:
n = 16

1 -> 2 -> 4 -> 8 -> 16

num == n, so true.

n = 12

1 -> 2 -> 4 -> 8 -> 16

16 > 12, so false.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class BetterSolution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        long long num = 1;

        while (num < n) {
            num = num * 2;
        }

        return num == n;
    }
};

/*
==================================================
APPROACH 3: OPTIMAL - BIT MANIPULATION
==================================================

Initial Intuition:
Every positive power of 2 has exactly one set bit
(1 in its binary representation).

Examples:

1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000

Important Property:
n & (n - 1) removes the rightmost set bit.

For powers of 2, only one set bit exists.
Therefore, n & (n - 1) becomes 0.

Dry Run 1:
n = 8

n     = 1000
n - 1 = 0111
        ----
AND   = 0000

Result = 0, so true.

Dry Run 2:
n = 12

n     = 1100
n - 1 = 1011
        ----
AND   = 1000

Result != 0, so false.

Steps:
1. If n <= 0, return false.
2. Check whether (n & (n - 1)) == 0.
3. If true, n is a power of 2.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        if ((n & (n - 1)) == 0) {
            return true;
        }

        return false;
    }
};

/*
==================================================
EDGE CASES
==================================================

1. n = 1  -> true
2. n = 0  -> false
3. n = -2 -> false
4. n = 2  -> true
5. n = 16 -> true
6. n = 12 -> false
7. n = 32 -> true

==================================================
KEY LEARNINGS
==================================================

1. Repeated division helps identify powers of 2.
2. Repeated multiplication generates powers of 2.
3. A positive power of 2 has exactly one set bit.
4. n & (n - 1) removes the rightmost set bit.
5. Bit manipulation provides O(1) time complexity.

Final Approach:
Optimal - Bit Manipulation.
*/
