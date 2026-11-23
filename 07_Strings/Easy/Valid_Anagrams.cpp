
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Valid Anagram
LeetCode: 242
Workbook: #51
Difficulty: Easy
Pattern: String Manipulation & Hashing
Technique: Character Frequency Counting
Data Structure: Fixed-size Frequency Array

--------------------------------------------------
1. PROBLEM UNDERSTANDING
--------------------------------------------------
Given two strings s and t, determine whether t is
an anagram of s.

Two strings are anagrams if they contain exactly
the same characters with the same frequencies,
regardless of their order.

--------------------------------------------------
2. BRUTE-FORCE APPROACH
--------------------------------------------------
Sort both strings and compare them.

If the sorted strings are equal, they are anagrams.

Time Complexity: O(n log n)
Space Complexity: Depends on sorting and copies.

--------------------------------------------------
3. OPTIMAL APPROACH: FREQUENCY ARRAY
--------------------------------------------------
Use an array of size 26 to store character frequencies.

Step 1: If the string lengths differ, return false.

Step 2: Traverse string s and increment the frequency
        of each character.

Step 3: Traverse string t and decrement the frequency
        of each character.

Step 4: Check all 26 frequency positions.
        If any value is non-zero, return false.

Step 5: If all frequencies are zero, return true.

--------------------------------------------------
4. WHY DOES IT WORK?
--------------------------------------------------
Anagrams must contain identical character frequencies.

Incrementing for s and decrementing for t cancels
matching character counts.

If every frequency becomes zero, both strings
contain exactly the same characters.

--------------------------------------------------
5. DRY RUN
--------------------------------------------------
s = "aabb"
t = "abab"

After processing s:
a -> 2
b -> 2

After processing t:
a -> 0
b -> 0

All remaining frequencies are zero.

Result: true

--------------------------------------------------
6. EDGE CASES
--------------------------------------------------
1. Different string lengths -> false
2. Both strings empty -> true
3. Identical strings -> true
4. Different character frequencies -> false
5. Repeated characters -> handled correctly

--------------------------------------------------
7. COMPLEXITY ANALYSIS
--------------------------------------------------
Time Complexity: O(n)
- Traverse s: O(n)
- Traverse t: O(n)
- Check 26 positions: O(1)

Auxiliary Space: O(1)
- The frequency array always has 26 positions.

--------------------------------------------------
8. KEY LEARNINGS
--------------------------------------------------
1. Character frequency counting.
2. Fixed-size arrays for restricted alphabets.
3. Hashing and frequency-based problem patterns.
4. Reducing sorting-based O(n log n) work to O(n).

--------------------------------------------------
IMPLEMENTATION
--------------------------------------------------
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Check whether both strings have equal length.
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Initialize frequency array.
        int freq[26] = {0};

        // Step 3: Increment frequencies for string s.
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 4: Decrement frequencies for string t.
        for (char ch : t) {
            freq[ch - 'a']--;
        }

        // Step 5: Verify that every frequency is zero.
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
