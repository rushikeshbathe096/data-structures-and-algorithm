/*
Problem:
Given a positive integer n, determine whether it is a happy number.A happy number is obtained by repeatedly replacing the number with the sum of the squares of its digits until it becomes 1. If the process enters a cycle that does not include 1, the number is not happy.

Example:
Input: n = 19
Output: true

Constraints:
1 <= n <= 2^31 - 1

Approach:
Create a helper function to compute the sum of the squares of the digits.Use an unordered_set to keep track of previously seen values. Repeatedly compute the new value until it becomes 1 or a repeated value is encountered. If a cycle is detected, return false.

Time Complexity: O(log n)
Each transformation processes the digits of the number, and the sequence quickly converges to a small range of values.

Space Complexity: O(log n)
Extra space is used by the unordered_set to store visited values.

Edge Cases:
- n is already 1.
- n enters a cycle and never reaches 1.
- Large values of n within the given constraints.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squaredigit(int n) {
        int ans = 0;
        while (n) {
            int rem = n % 10;
            ans += rem * rem;
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        int ans = squaredigit(n);
        unordered_set<int> st;
        while (ans != 1) {
            if (!st.count(ans)) {
                st.insert(ans);
                ans = squaredigit(ans);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << (sol.isHappy(n) ? "true" : "false") << endl;

    return 0;
}