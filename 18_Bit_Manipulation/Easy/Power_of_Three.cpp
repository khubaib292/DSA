
/*
=========================================================
Problem: Power of Three
LeetCode: 326
Difficulty: Easy
Pattern: Math / Number Theory
=========================================================

1. PROBLEM UNDERSTANDING

Given an integer n, determine whether it is a power
of three.

A number is a power of three if it can be expressed as:

    3^x = n

where x is a non-negative integer.

Examples:

Input: n = 27
Output: true

Explanation:
27 = 3 * 3 * 3 = 3^3

Input: n = 9
Output: true

Explanation:
9 = 3 * 3 = 3^2

Input: n = 10
Output: false

Explanation:
10 cannot be expressed as a power of three.

Input: n = 1
Output: true

Explanation:
1 = 3^0

Important:
- Negative numbers cannot be powers of three.
- Zero cannot be a power of three.
- One is a power of three.


=========================================================
2. APPROACH 1: BRUTE FORCE
   Repeated Division
=========================================================

Initial Intuition:

A power of three can be divided by 3 repeatedly
until we reach 1.

For example:

27 -> 9 -> 3 -> 1

If the number is divisible by 3 at every step and
eventually becomes 1, it is a power of three.

If at any point it is not divisible by 3, it is
not a power of three.

Algorithm:

1. Check whether n is less than or equal to zero.
   If yes, return false.
2. Run a while loop as long as n is divisible by 3.
3. Divide n by 3 in every iteration.
4. After the loop, check whether n is equal to 1.
5. If it is 1, return true; otherwise, return false.

Implementation:

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

Dry Run:

Example: n = 27

Iteration 1:
27 % 3 == 0
n = 27 / 3 = 9

Iteration 2:
9 % 3 == 0
n = 9 / 3 = 3

Iteration 3:
3 % 3 == 0
n = 3 / 3 = 1

Now:
1 % 3 != 0

Loop stops.

Finally:
n == 1

Output: true

Another Example: n = 12

12 % 3 == 0
n = 12 / 3 = 4

4 % 3 != 0

Loop stops.

Finally:
n == 1 is false.

Output: false

Complexity Analysis:

Time Complexity: O(log₃ n)
We divide the number by 3 in every iteration.

Space Complexity: O(1)
We use only a constant amount of extra space.


=========================================================
3. APPROACH 2: BETTER
   Repeated Multiplication
=========================================================

Initial Intuition:

Instead of repeatedly dividing n by 3, we can
generate powers of three starting from 1.

We know:

3^0 = 1
3^1 = 3
3^2 = 9
3^3 = 27
3^4 = 81

We keep multiplying the current number by 3 until
it becomes equal to or greater than n.

If it becomes equal to n, it is a power of three.

If it becomes greater than n, it is not a power
of three.

Algorithm:

1. If n is less than or equal to zero, return false.
2. Initialize num = 1.
3. Run a while loop while num is less than n.
4. Multiply num by 3 in every iteration.
5. Finally, check whether num is equal to n.

Implementation:

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

Dry Run:

Example: n = 27

Initially:
num = 1

Iteration 1:
num = 1 * 3 = 3

Iteration 2:
num = 3 * 3 = 9

Iteration 3:
num = 9 * 3 = 27

Now:
num < n is false.

Finally:
num == n

Output: true

Another Example: n = 10

Initially:
num = 1

Iteration 1:
num = 1 * 3 = 3

Iteration 2:
num = 3 * 3 = 9

Iteration 3:
num = 9 * 3 = 27

Now:
num is greater than n.

Finally:
num == n is false.

Output: false

Complexity Analysis:

Time Complexity: O(log₃ n)
We multiply by 3 in every iteration.

Space Complexity: O(1)
We use only a constant amount of extra space.

Note:
We use long long for num to avoid integer overflow
during multiplication.


=========================================================
4. APPROACH 3: OPTIMAL
   Mathematical Approach
=========================================================

Initial Intuition:

We know that every power of three is a factor
of another power of three.

Instead of repeatedly dividing or multiplying,
we can use a mathematical property.

For a signed 32-bit integer:

INT_MAX = 2147483647

The largest power of three that fits within this
range is:

3^19 = 1162261467

Every positive power of three within the signed
32-bit integer range divides 3^19 exactly.

For example:

1162261467 % 1  = 0
1162261467 % 3  = 0
1162261467 % 9  = 0
1162261467 % 27 = 0

But:

1162261467 % 10 != 0

Therefore, we can check whether n is positive
and whether it divides 1162261467 exactly.

Algorithm:

1. If n is less than or equal to zero, return false.
2. Check whether 1162261467 % n == 0.
3. If the remainder is zero, return true.
4. Otherwise, return false.

Implementation:

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

Dry Run:

Example: n = 27

Check:

1162261467 % 27 == 0

The remainder is zero.

Output: true

Another Example: n = 10

Check:

1162261467 % 10 != 0

The remainder is not zero.

Output: false

Complexity Analysis:

Time Complexity: O(1)
We perform a fixed number of mathematical operations.

Space Complexity: O(1)
No additional data structures are used.

Important:
This mathematical constant is based on the signed
32-bit integer constraint of the problem.


=========================================================
5. EDGE CASES
=========================================================

1. n = 1
   Output: true
   Because 3^0 = 1.

2. n = 0
   Output: false

3. n = -3
   Output: false

4. n = 3
   Output: true

5. n = 9
   Output: true

6. n = 10
   Output: false

7. n = 27
   Output: true


=========================================================
6. APPROACH COMPARISON
=========================================================

Approach 1: Repeated Division
Time: O(log₃ n)
Space: O(1)

Approach 2: Repeated Multiplication
Time: O(log₃ n)
Space: O(1)

Approach 3: Mathematical Approach
Time: O(1)
Space: O(1)

The mathematical approach is optimal because
it checks the result in constant time.


=========================================================
7. KEY LEARNINGS
=========================================================

1. Repeated division can help identify powers of a number.

2. Repeated multiplication can generate powers of a number.

3. Mathematical properties can sometimes reduce
   an iterative solution to constant time.

4. Always handle zero and negative numbers.

5. Understand how the optimal mathematical constant
   is derived instead of memorizing it blindly.

=========================================================
*/
