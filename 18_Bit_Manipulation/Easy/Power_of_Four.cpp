
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Power of Four
LeetCode: 342
Workbook: #453
Difficulty: Easy
Pattern: Bit Manipulation / Math

Problem Understanding:
Given an integer n, determine whether it is a power of 4.

A number is a power of 4 if it can be expressed as:
n = 4^x, where x is a non-negative integer.

Examples:
n = 1  -> true  (4^0)
n = 4  -> true  (4^1)
n = 16 -> true  (4^2)
n = 8  -> false
n = 0  -> false
n = -4 -> false

==================================================
APPROACH 1: BRUTE FORCE - REPEATED DIVISION
==================================================

Initial Intuition:
A power of 4 can be repeatedly divided by 4
until we reach 1.

If the number is divisible by 4 at every step
and eventually becomes 1, it is a power of 4.

Steps:
1. If n <= 0, return false.
2. Divide n by 4 while it is completely divisible by 4.
3. Continue until n is no longer divisible by 4.
4. If the final value is 1, return true.
5. Otherwise, return false.

Dry Run:
n = 64

64 -> 16 -> 4 -> 1

Final value = 1, so true.

n = 20

20 -> 5

5 is not divisible by 4.
Final value = 5, so false.

Time Complexity: O(log₄ n)
Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        while (n % 4 == 0) {
            n = n / 4;
        }

        return n == 1;
    }
};

/*
==================================================
APPROACH 2: BETTER - REPEATED MULTIPLICATION
==================================================

Initial Intuition:
Instead of repeatedly dividing n by 4,
we can generate powers of 4 starting from 1.

We keep multiplying the current number by 4
until it becomes equal to or greater than n.

If the generated number is equal to n,
it is a power of 4.

Steps:
1. If n <= 0, return false.
2. Initialize num = 1.
3. Multiply num by 4 while num < n.
4. If num == n, return true.
5. Otherwise, return false.

Dry Run:
n = 16

1 -> 4 -> 16

num == n, so true.

n = 20

1 -> 4 -> 16 -> 64

64 > 20, so false.

Time Complexity: O(log₄ n)
Space Complexity: O(1)
*/

class BetterSolution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        long long num = 1;

        while (num < n) {
            num = num * 4;
        }

        return num == n;
    }
};

/*
==================================================
APPROACH 3: OPTIMAL - BIT MANIPULATION
==================================================

Initial Intuition:
We already know that every power of 4 is also
a power of 2.

However, every power of 2 is not necessarily
a power of 4.

The difference can be identified using binary
bit positions.

Binary Representation:

1  = 00000001  -> Power of 4
2  = 00000010  -> Not a power of 4
4  = 00000100  -> Power of 4
8  = 00001000  -> Not a power of 4
16 = 00010000  -> Power of 4
32 = 00100000  -> Not a power of 4

Important Properties:

1. A positive power of 2 has exactly one set bit.

   We can check this using:
   (n & (n - 1)) == 0

2. For a power of 4, the single set bit must
   be at an even position.

   Bit positions are counted from right to left,
   starting from position 0.

3. The mask 0x55555555 has set bits at all even
   positions in a 32-bit integer.

   Binary pattern:
   01010101010101010101010101010101

4. We use the mask to check whether the set bit
   of n is at an even position.

Steps:
1. If n <= 0, return false.
2. Check whether n is a power of 2 using:
   (n & (n - 1)) == 0
3. Check whether n has a set bit at an even
   position using:
   (n & 0x55555555) != 0
4. If both conditions are true, return true.
5. Otherwise, return false.

Dry Run 1:
n = 16

Binary:
n     = 00010000
n - 1 = 00001111

First Check:
n & (n - 1) = 00000000

So, n has exactly one set bit.

Second Check:
n & 0x55555555

The set bit of 16 is at position 4,
which is an even position.

Both conditions are true.

Output: true.

Dry Run 2:
n = 8

Binary:
n     = 00001000
n - 1 = 00000111

First Check:
n & (n - 1) = 00000000

So, n has exactly one set bit.

Second Check:
The set bit of 8 is at position 3,
which is an odd position.

The even-position mask does not match.

Output: false.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        // Check whether n has exactly one set bit.
        if ((n & (n - 1)) == 0) {

            // Check whether the set bit is at an even position.
            if ((n & 0x55555555) != 0) {
                return true;
            }
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
3. n = -4  -> false
4. n = 4   -> true
5. n = 8   -> false
6. n = 16  -> true
7. n = 32  -> false
8. n = 64  -> true
9. n = 12  -> false

==================================================
KEY LEARNINGS
==================================================

1. Repeated division helps identify powers of 4.
2. Repeated multiplication generates powers of 4.
3. Every power of 4 is also a power of 2.
4. A power of 2 has exactly one set bit.
5. A power of 4 has its single set bit at an even position.
6. n & (n - 1) checks whether there is exactly one set bit.
7. 0x55555555 checks for set bits at even positions.
8. Combining both bit manipulation conditions
   gives an O(1) solution.

Final Approach:
Optimal - Bit Manipulation.
*/
