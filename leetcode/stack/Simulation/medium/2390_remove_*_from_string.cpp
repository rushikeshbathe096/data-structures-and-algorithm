/*
Problem:
Given a string s containing lowercase letters and '*' characters, remove each
star along with the closest non-star character to its left, and return the
final string after all stars have been removed.

Example:
Input: s = "leet**cod*e"
Output: "lecoe"

Approach:
Traverse the string from left to right and build the answer string; add normal
characters to it, and whenever a '*' is encountered, remove the last character
from the answer, which represents the closest non-star character to its left.

Time Complexity: O(n)
Space Complexity: O(n)

Edge Cases:
- All characters are removed.
- No stars in the string.
- Multiple consecutive stars.
- String of length 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!ans.empty()) ans.pop_back();
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};