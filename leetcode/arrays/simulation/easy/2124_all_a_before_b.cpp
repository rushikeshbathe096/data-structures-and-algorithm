/*
Problem Statement:
Given a string s consisting only of 'a' and 'b', return true if all 'a' characters
appear before all 'b' characters. Otherwise, return false.

Example:
Input: s = "aaabbb"
Output: true

Constraints:
- 1 <= s.length <= 100, s consists only of 'a' and 'b'

Approach:
Iterate and wherever ba pattern is found, return false. If the loop ends without finding the pattern, return true.

Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        for(int i = 1; i < s.size(); i++){
            if(s[i] == 'a' && s[i - 1] == 'b') return false;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;

    cout << Solution().checkString(s) << endl;
    return 0;
}