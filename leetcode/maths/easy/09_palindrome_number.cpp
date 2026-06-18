#include <bits/stdc++.h>
using namespace std;

/*
Problem: Palindrome Number (LeetCode 9)
Topic: Numbers
Difficulty: Easy

Description:
Return true if x is a palindrome integer, false otherwise.

Approach:
- If x < 0, return false
- Otherwise, reverse x and compare with original

Time Complexity: O(log10(n))
Space Complexity: O(1)
Edge Cases: x = 0, negative numbers
*/

class Solution {
public:
    bool isPalindrome(long long x) {
        if(x < 0) return false;
        long long a = x;
        long long rev = 0;
        while(a) {
            int rem = a % 10;
            a /= 10;
            rev = 10 * rev + rem;
        }
        return rev == x;
    }
};

int main() {
    Solution s;
    long long x;
    cout << "Enter an integer: ";
    cin >> x;

    bool result = s.isPalindrome(x);
    cout << "Is Palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}

