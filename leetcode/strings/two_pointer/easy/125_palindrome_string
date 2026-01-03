#include <bits/stdc++.h>
using namespace std;

/*
Description:
Check if a given string is a palindrome, considering only alphanumeric characters 
and ignoring case.

Approach:
Take two pointers at start and end and compare, skipping non-alphanumeric characters.

Time Complexity: O(n), where n is the length of the string
Space Complexity: O(1)
Edge Cases:
- Empty string
- Single-character string
- Strings with only non-alphanumeric characters
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    string s;
    getline(cin, s);
    cout << (Solution().isPalindrome(s) ? "Yes" : "No") << endl;
    return 0;
}

