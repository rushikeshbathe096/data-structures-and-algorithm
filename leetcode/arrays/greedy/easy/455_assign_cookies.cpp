/*
Problem:
Given the greed factor of each child and the size of each cookie, assign at
most one cookie to each child such that a child is satisfied only if the
cookie size is at least its greed factor. Return the maximum number of
content children.

Example:
Input: g = [1,2,3], s = [1,1]
Output: 1

Approach:
Sort both the greed factors and cookie sizes, then use two pointers to assign
the smallest cookie that can satisfy the current child; if the cookie is too
small, try a larger cookie, otherwise assign it and move to the next child,
which maximizes the total number of satisfied children.

Time Complexity: O(n log n + m log m)-Sorting the greed factors and cookie sizes takes O(n log n + m log m),
and the two-pointer traversal processes each element at most once.

Space Complexity: O(1)-No extra data structures proportional to the input size are used; the
algorithm only uses a few variables (excluding the space used by sorting).

Edge Cases:
- No cookies available.
- More cookies than children.
- More children than cookies.
- All cookies are too small.
- All children can be satisfied.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, cnt = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return cnt;
    }
};
