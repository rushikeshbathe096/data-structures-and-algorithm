
/*
Problem: Reverse Integer (LeetCode 7)
Topic: Numbers
Difficulty: Easy

Description:
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], return 0.

Example:
Input: x = -123
Output: -321

Approach:
- Extract last digit using x % 10
- Append to result: rev = rev * 10 + rem
- Remove last digit from x: x /= 10
- Check overflow before multiplying by 10
- Negative numbers are handled automatically by C++ % and / rules

Time Complexity: O(log10(n))
Space Complexity: O(1)

Edge Cases:
- x = 0
- x = INT_MAX or INT_MIN
- Numbers ending with 0
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x) {
            int rem = x % 10;
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) return 0;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }
};

int main() {
    Solution s;
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    int result = s.reverse(x);
    cout << "Reversed integer: " << result << endl;
    return 0;
}
