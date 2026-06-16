/*
Problem:
Process a string consisting of lowercase English letters and the special characters
'*', '#', and '%' to build a new string result.

Rules:
- Lowercase letter: append it to the result.- '*': remove the last character from the result if it exists.- '#': duplicate the current result and append it to itself.- '%': reverse the current result.
Return the final processed string.

Example:
s = "a#b%*"
Output: "ba"

Constraints:
1 <= s.length <= 20
s consists only of lowercase English letters and the characters '*', '#', and '%'.

Approach:
Traverse and follow rules

Time Complexity: O(n * m)
Where n is the length of s and m is the current size of the result string.
The '#' and '%' operations may process the entire result string.

Space Complexity: O(m)
The extra space used is the final result string.

Edge Cases:
- '*' encountered when the result is empty.
- '#' applied to an empty string.
- '%' applied to an empty or single-character string.
- Multiple consecutive special characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]))
                ans += s[i];
            else if (s[i] == '*') {
                if (!ans.empty())
                    ans.pop_back();
            }
            else if (s[i] == '#')
                ans += ans;
            else
                reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.processStr(s) << endl;

    return 0;
}