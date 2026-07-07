/*
Problem:
The Tribonacci sequence is defined as:
T0 = 0, T1 = 1, T2 = 1, and
Tn = Tn-1 + Tn-2 + Tn-3 for n >= 3.

Given an integer n, return the nth Tribonacci number.

Example:
Input: n = 4
Output: 4

State:
dp[i] = The ith Tribonacci number.

Approach 1 (Memoization):
The nth Tribonacci number depends on the previous three Tribonacci numbers.
Recursively compute each value and store it in a DP array so that every state
is calculated only once and reused whenever needed.

Transition:
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

Base Cases:
dp[0] = 0
dp[1] = 1
dp[2] = 1

Time Complexity: O(n)
Space Complexity: O(n)

Approach 2 (Tabulation):
Create a DP array and fill it from 0 to n using the same transition. Since
every state depends only on the previous three states, compute them in order
until reaching the required answer.

Transition:
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3 (Space Optimized):
Since each state depends only on the previous three values, keep only those
three values instead of the entire DP array and update them while traversing
from 3 to n.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- n = 0.
- n = 1 or n = 2.
- Maximum allowed value of n.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Memoization --------------------

class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(dp, n - 1) +
                       solve(dp, n - 2) +
                       solve(dp, n - 3);
    }

    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};

// -------------------- Approach 2: Tabulation --------------------

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }
};

// -------------------- Approach 3: Space Optimized --------------------

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int prev3 = 0, prev2 = 1, prev1 = 1;

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};