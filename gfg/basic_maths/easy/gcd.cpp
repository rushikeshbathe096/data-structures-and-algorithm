/*
Problem: Greatest Common Divisor (GCD)
Topic: Numbers
Difficulty: Easy

Description:
Given two integers a and b, find their Greatest Common Divisor (GCD).
The GCD of two numbers is the largest number that divides both of them.

Example:
Input: a = 12, b = 18
Output: 6

Approach:
Use the Euclidean Algorithm:

Iterative Method:
- Repeatedly replace (a, b) with (b, a % b)
- Continue until b becomes 0
- The remaining value of a is the GCD

Recursive Method:
- Base Case: if b == 0, return a
- Otherwise return gcd(b, a % b)

Time Complexity: O(log(min(a, b)))
At each step, the values reduce significantly due to modulo operation.
In the worst case, the number of steps is proportional to log of the smaller number.

Space Complexity:
- Iterative: O(1)
- Recursive: O(log(min(a, b))) due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        // Iterative approach
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Recursive version (optional)
    int gcdRecursive(int a, int b) {
        if (b == 0) return a;
        return gcdRecursive(b, a % b);
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    cout << Solution().gcd(a, b);

    return 0;
}