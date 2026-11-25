
/*
========================================================
Problem Name : Group Anagrams
LeetCode     : 49
Difficulty   : Medium
Pattern      : String Manipulation & Hashing
Data Structure: HashMap, Frequency Array
========================================================

1. PROBLEM UNDERSTANDING

Given an array of strings, group all strings that are
anagrams of each other.

Anagrams contain the same characters with the same
frequency, but their order can be different.

Example:
Input:
["eat", "tea", "tan", "ate", "nat", "bat"]

Output:
[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]


2. INITIAL INTUITION

We need to identify strings that contain the same
characters with identical frequencies.

We studied three approaches:

- Brute Force: Compare every string with other strings.
- Better: Sort each string and use the sorted string
  as a HashMap key.
- Optimal: Use character frequency as the HashMap key.


========================================================
APPROACH 1: BRUTE FORCE
========================================================

IDEA:

1. Create a visited array to track grouped strings.
2. Select an unvisited string.
3. Compare it with every remaining unvisited string.
4. Use an anagram-checking function to compare strings.
5. If they are anagrams, add them to the same group.
6. Store the completed group in the answer.

WHY IT WORKS:

Every string is compared with the selected starting
string. All matching anagrams are collected together.

IMPLEMENTATION:

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();

    vector<vector<string>> ans;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;

        for (int j = i + 1; j < n; j++) {
            if (!visited[j] && isAnagram(strs[i], strs[j])) {
                group.push_back(strs[j]);
                visited[j] = true;
            }
        }

        ans.push_back(group);
    }

    return ans;
}

COMPLEXITY:

Time: O(N^2 * K log K)
Space: O(N * K) for grouping and output,
       excluding temporary sorting and visited storage.

N = Number of strings
K = Maximum length of a string


========================================================
APPROACH 2: BETTER APPROACH
SORTING + HASHMAP
========================================================

IDEA:

Instead of comparing every string with every other string,
sort each string alphabetically.

Anagrams produce the same sorted string.

Example:

"eat" -> "aet"
"tea" -> "aet"
"ate" -> "aet"

"tan" -> "ant"
"nat" -> "ant"

"bat" -> "abt"

Use the sorted string as the HashMap key and store
the original strings as values.

IMPLEMENTATION:

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> groups;

    for (string s : strs) {

        string key = s;

        sort(key.begin(), key.end());

        groups[key].push_back(s);
    }

    vector<vector<string>> ans;

    for (auto& it : groups) {
        ans.push_back(it.second);
    }

    return ans;
}

WHY IT WORKS:

All anagrams produce the same sorted representation.
Therefore, they are stored under the same HashMap key.

COMPLEXITY:

Time: O(N * K log K) average
Space: O(N * K) for HashMap and grouped output.


========================================================
APPROACH 3: OPTIMAL APPROACH
FREQUENCY COUNTING + HASHMAP
========================================================

IDEA:

Instead of sorting every string, count the frequency
of every character.

Since the problem uses lowercase English letters,
we can use a fixed-size frequency array of 26 elements.

For every string:

1. Create a frequency array.
2. Count the occurrences of each character.
3. Convert the frequency array into a unique string key.
4. Insert the original string into the corresponding
   HashMap group.
5. Transfer all groups into the final answer.

FREQUENCY COUNTING:

int freq[26] = {0};

for (char ch : s) {
    freq[ch - 'a']++;
}

KEY GENERATION:

string key = "";

for (int i = 0; i < 26; i++) {
    key += to_string(freq[i]) + "#";
}

The '#' separator keeps frequency values distinct.

HASHMAP INSERTION:

groups[key].push_back(s);

If the key already exists, the original string is
added to its existing group.

Otherwise, a new group is created automatically.

WHY IT WORKS:

Anagrams always have identical character frequencies.

For example:

"eat", "tea", and "ate" have identical frequencies.

Therefore, all three strings generate the same key
and are stored in the same group.


========================================================
OPTIMAL IMPLEMENTATION
========================================================

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;
        vector<vector<string>> ans;

        // Process every string
        for (const string& s : strs) {

            // Step 1: Count character frequencies
            int freq[26] = {0};

            for (char ch : s) {
                freq[ch - 'a']++;
            }

            // Step 2: Generate frequency key
            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            // Step 3: Group original strings
            groups[key].push_back(s);
        }

        // Step 4: Transfer groups into answer
        for (auto& it : groups) {
            ans.push_back(it.second);
        }

        return ans;
    }
};


========================================================
DRY RUN
========================================================

Input:
["eat", "tea", "tan", "ate", "nat", "bat"]

String: "eat"
Frequency key: Same signature as "tea" and "ate"
Group: ["eat"]

String: "tea"
Frequency key: Same as "eat"
Group: ["eat", "tea"]

String: "tan"
Frequency key: New signature
Group: ["tan"]

String: "ate"
Frequency key: Same as "eat"
Group: ["eat", "tea", "ate"]

String: "nat"
Frequency key: Same as "tan"
Group: ["tan", "nat"]

String: "bat"
Frequency key: New signature
Group: ["bat"]

Final groups:

[
    ["eat", "tea", "ate"],
    ["tan", "nat"],
    ["bat"]
]

Note: The order of groups may differ because
unordered_map does not guarantee iteration order.


========================================================
EDGE CASES
========================================================

1. Empty input:
   Input: []
   Output: []

2. Single string:
   Input: ["abc"]
   Output: [["abc"]]

3. All strings are anagrams:
   Input: ["abc", "bca", "cab"]
   Output: [["abc", "bca", "cab"]]

4. No strings are anagrams:
   Input: ["abc", "def", "ghi"]
   Output: [["abc"], ["def"], ["ghi"]]

5. Repeated strings:
   Input: ["eat", "eat", "tea"]
   Output: [["eat", "eat", "tea"]]


========================================================
COMPLEXITY ANALYSIS
========================================================

Let:
N = Number of strings
K = Maximum length of a string

Brute Force:
Time: O(N^2 * K log K)

Better (Sorting + HashMap):
Time: O(N * K log K)

Optimal (Frequency + HashMap):
Time: O(N * K) average

Space:
O(N * K) for HashMap and grouped output.
Frequency array: O(1) auxiliary space.


========================================================
KEY LEARNINGS
========================================================

1. Anagrams have identical character frequencies.
2. Frequency arrays can be used to identify anagrams.
3. HashMaps can group elements using a common key.
4. unordered_map provides average O(1) lookup and insertion.
5. A unique frequency signature avoids repeated sorting.
6. Choose a fixed-size array when the character set
   is known and limited.

========================================================
