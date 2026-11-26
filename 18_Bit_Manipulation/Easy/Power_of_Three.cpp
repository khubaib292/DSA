
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Power of Three
LeetCode: 326
Workbook: #453
Difficulty: Easy
Pattern: Math / Number Theory

Problem Understanding:
Given an integer n, determine whether it is a power of 3.

A number is a power of 3 if it can be expressed as:
n = 3^x, where x is a non-negative integer.

Examples:
n = 1  -> true  (3^0)
n = 3  -> true  (3^1)
n = 27 -> true  (3^3)
n = 10 -> false
n = 0  -> false
n = -3 -> false

==================================================
APPROACH 1: BRUTE FORCE - REPEATED DIVISION
==================================================

Initial Intuition:
A power of 3 can be repeatedly divided by 3
until we reach 1.

If the number is divisible by 3 at every step
and eventually becomes 1, it is a power of 3.

Steps:
1. If n <= 0, return false.
2. Divide n by 3 while it is completely divisible by 3.
3. Continue this process until n is no longer divisible by 3.
4. If the final value is 1, return true.
5. Otherwise, return false.

Dry Run:
n = 27

27 -> 9 -> 3 -> 1

Final value = 1, so true.

n = 12

12 -> 4

4 is not divisible by 3.
Final value = 4, so false.

Time Complexity: O(log₃ n)
Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        while (n % 3 == 0) {
            n = n / 3;
        }

        return n == 1;
    }
};

/*
==================================================
APPROACH 2: BETTER - REPEATED MULTIPLICATION
==================================================

Initial Intuition:
Instead of repeatedly dividing n by 3,
we can generate powers of 3 starting from 1.

We keep multiplying the current number by 3
until it becomes equal to or greater than n.

If the generated number is equal to n,
it is a power of 3.

Steps:
1. If n <= 0, return false.
2. Initialize num = 1.
3. Multiply num by 3 while num < n.
4. If num == n, return true.
5. Otherwise, return false.

Dry Run:
n = 27

1 -> 3 -> 9 -> 27

num == n, so true.

n = 10

1 -> 3 -> 9 -> 27

27 > 10, so false.

Time Complexity: O(log₃ n)
Space Complexity: O(1)
*/

class BetterSolution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        long long num = 1;

        while (num < n) {
            num = num * 3;
        }

        return num == n;
    }
};

/*
==================================================
APPROACH 3: OPTIMAL - MATHEMATICAL APPROACH
==================================================

Initial Intuition:
We know that every positive power of 3 divides
another power of 3 exactly.

For a signed 32-bit integer:

INT_MAX = 2147483647

The largest power of 3 that fits within this
range is:

3^19 = 1162261467

Every positive power of 3 within the signed
32-bit integer range divides 3^19 exactly.

Therefore, instead of repeatedly dividing or
multiplying, we can check whether n divides
1162261467 without leaving a remainder.

Steps:
1. If n <= 0, return false.
2. Check whether 1162261467 % n == 0.
3. If the remainder is 0, return true.
4. Otherwise, return false.

Dry Run 1:
n = 27

1162261467 % 27 = 0

Remainder = 0, so true.

Dry Run 2:
n = 10

1162261467 % 10 != 0

Remainder is not 0, so false.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        if (1162261467 % n == 0) {
            return true;
        }

        return false;
    }
};

/*
==================================================
EDGE CASES
==================================================

1. n = 1   -> true
2. n = 0   -> false
3. n = -3  -> false
4. n = 3   -> true
5. n = 9   -> true
6. n = 10  -> false
7. n = 27  -> true
8. n = 81  -> true

==================================================
KEY LEARNINGS
==================================================

1. Repeated division helps identify powers of 3.
2. Repeated multiplication generates powers of 3.
3. Mathematical properties can reduce an iterative
   solution to constant time.
4. Always handle zero and negative numbers.
5. 3^19 is the largest power of 3 within the
   signed 32-bit integer range.
6. Understand how mathematical constants are
   derived instead of memorizing them.

Final Approach:
Optimal - Mathematical Approach.
*/
