```cpp
/*
Problem:
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

Example:
haystack = "sadbutsad", needle = "sad"
Output: 0

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.

Approach:
We use the built-in find() function provided by the string class.
It returns the index of the first occurrence of needle in haystack.
If the substring is not found, find() automatically returns -1
(string::npos is converted to -1 when returned as an int).

Time Complexity: O(n * m) in the worst case
Where n is the length of haystack and m is the length of needle.

Space Complexity: O(1)
No extra space is used.

Edge Cases:
- needle is present at the beginning of haystack.
- needle is present at the end of haystack.
- needle does not exist in haystack.
- haystack and needle are identical.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {
    string haystack, needle;
    cin >> haystack >> needle;

    Solution sol;
    int index = sol.strStr(haystack, needle);

    cout << index << endl;

    return 0;
}
```
