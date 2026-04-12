/*
Problem: Print All Divisors of a Number
Topic: Numbers
Difficulty: Medium

Description:
Given an integer n, print all its divisors in sorted order.

Example:
Input: n = 12
Output: 1 2 3 4 6 12

Approach:
- Iterate from 1 to sqrt(n)
- If i divides n:
    - Add i to the list
    - If i is not equal to n/i, add n/i as well
- This ensures we capture divisors in pairs
- Finally, sort the list to print in increasing order

Time Complexity: O(√n + k log k)
- We iterate up to √n
- Sorting takes O(k log k), where k is number of divisors

Space Complexity: O(k)
- We store all divisors in a vector
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> divisors;

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                divisors.push_back(i);

                if(i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());

        for(int a : divisors) {
            cout << a << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;

    Solution().print_divisors(n);

    return 0;
}