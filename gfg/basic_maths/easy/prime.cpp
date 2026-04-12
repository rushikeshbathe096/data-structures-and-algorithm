/*
Problem: Check Prime Number
Topic: Numbers
Difficulty: Easy

Description:
Given an integer n, determine whether it is a prime number.
A prime number is a number greater than 1 that has no divisors other than 1 and itself.

Example:
Input: n = 7
Output: true

Approach:
- If n <= 1, it is not prime,Iterate from 2 to √n, If any number divides n, it is not prime

Time Complexity: O(√n)
We only check divisibility up to √n because any factor greater than √n
would have a corresponding factor smaller than √n.

Space Complexity: O(1)
No extra space is used apart from a few variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPrime(int n) {
        if(n <= 1) return false;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;

    cout << (Solution().isPrime(n) ? "true" : "false");

    return 0;
}