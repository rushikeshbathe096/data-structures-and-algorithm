/*
Problem:
You are climbing a staircase with n steps, and at each move you can climb
either 1 or 2 steps. Return the total number of distinct ways to reach the top.

Example:
Input: n = 3
Output: 3

Approach 1 (Space Optimized DP):
The number of ways to reach the current step depends only on the previous two
steps, so keep track of the last two answers and update them iteratively to
compute the result using constant extra space.

Time Complexity: O(n)
Space Complexity: O(1)

Approach 2 (Memoization):
Recursively calculate the number of ways to reach each step, store the computed
results in a DP array, and reuse them whenever needed to avoid repeated work.

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3 (Tabulation):
Build a DP array from the bottom up, where each position stores the number of
ways to reach that step using the answers of the previous two steps.

Time Complexity: O(n)
Space Complexity: O(n)

Edge Cases:
- n = 1.
- n = 2.
- Maximum allowed value of n.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Space Optimized DP --------------------

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// -------------------- Approach 2: Memoization --------------------

class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if (n <= 1) return 1;

        if (dp[n] != -1)
            return dp[n];

        dp[n - 1] = solve(dp, n - 1);
        dp[n - 2] = solve(dp, n - 2);

        return dp[n] = dp[n - 1] + dp[n - 2];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};

// -------------------- Approach 3: Tabulation --------------------

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};