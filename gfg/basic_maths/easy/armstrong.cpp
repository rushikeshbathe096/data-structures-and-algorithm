/*
Problem: Armstrong Number
Topic: Numbers
Difficulty: Easy

Description:
An Armstrong number is a number such that the sum of its digits each raised 
to the power of the number of digits is equal to the number itself.

Example:
Input: n = 153
Output: true

Approach:
To check convert a number to string and then find sum of power of each digit and compare it to the original number

Time Complexity: O(d)
Where d is the number of digits in n. We iterate through each digit once.
Since d ≈ log10(n), the complexity can also be written as O(log n).

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool armstrongNumber(int n) {
        string s = to_string(n);
        int k = s.size();
        
        int sum = 0;
        for(char c : s) {
            sum += pow(c - '0', k);
        }
        
        return sum == n;
    }
};

int main() {
    int n;
    cin >> n;

    cout << (Solution().armstrongNumber(n) ? "true" : "false");

    return 0;
}