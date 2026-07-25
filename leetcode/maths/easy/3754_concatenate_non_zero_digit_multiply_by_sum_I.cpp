/*
Problem:
Given an integer n, form a new integer x by concatenating all the non-zero
digits of n in their original order. Let sum be the sum of the digits in x.
Return the value of x * sum.

Example:
Input: n = 10203004
Output: 12340

Approach:
Extract the digits of n one by one, ignore zeros, and store the non-zero digits
while also calculating their sum. Reverse the collected digits to restore their
original order, convert them into an integer x, and return x multiplied by the
sum of its digits.

Time Complexity: O(d)
The number is processed one digit at a time, where d is the number of digits
in n.

Space Complexity: O(d)
An additional string is used to store the non-zero digits before forming x.

Edge Cases:
- n = 0.
- All digits except one are zero.
- No zero digits are present.
- Non-zero digits appear in any position.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string a = "";
        long long sum = 0;

        while (n) {
            int rem = n % 10;

            if (rem != 0) {
                sum += rem;
                a += to_string(rem);
            }

            n /= 10;
        }

        reverse(a.begin(), a.end());

        int x = stoi(a);

        return 1LL * x * sum;
    }
};