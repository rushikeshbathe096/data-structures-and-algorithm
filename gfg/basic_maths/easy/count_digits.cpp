/*
Problem Statement:
Given an integer n, return the number of digits in it.

Example:
Input: n = 12345
Output: 5

Constraints:
- n >= 0

Intuition + Approach:
Log10(n) gives the number of digits in n. We can add 1 to it to get the total count of digits. If n is 0, we should return 1 since 0 has one digit.

Edge Cases:
- n = 0 -> return 1

Complexity:
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if (n == 0) return 1;
        return (int)(log10(n) + 1);
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().countDigits(n) << endl;
    return 0;
}