/*
Problem:
Given a string text, return the maximum number of times the word "balloon"
can be formed using its characters. Each character in text can be used at
most once.

Example:
Input: text = "loonbalxballpoon"
Output: 2

Approach:
Count the frequency of every character in the string, then find how many times
the letters needed to form "balloon" are available; since 'l' and 'o' appear
twice in "balloon", divide their counts by 2, and the minimum of all required
character counts gives the maximum number of complete words that can be formed.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Not enough characters to form "balloon".
- Exactly enough characters to form one or more words.
- Extra unused characters are present.
- Empty count for any required character.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26);

        for (char c : text)
            v[c - 'a']++;

        return min({v[0], v[1], v[11] / 2, v[13], v[14] / 2});
    }
};