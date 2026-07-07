/*
Problem:
Given a string s consisting only of 'a', 'b', and 'c', repeatedly remove a
non-empty prefix and suffix made of the same character without overlapping,
and return the minimum possible length of the remaining string.

Example:
Input: s = "cabaabac"
Output: 0

Approach:
Use two pointers starting from both ends of the string; whenever the characters
at both ends are the same, skip all consecutive occurrences of that character
from both sides, and continue until the end characters differ or the pointers
meet, then the remaining length is the answer.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- No characters can be removed.
- Entire string is removed.
- String contains only one character.
- All characters are the same.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r && s[l] == s[r]) {
            char ch = s[l];

            while (l < r && s[l] == ch) l++;
            while (r >= l && s[r] == ch) r--;
        }

        return r - l + 1;
    }
};