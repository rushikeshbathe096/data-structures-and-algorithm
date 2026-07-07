/*
Problem:
You are given an array cost where cost[i] is the cost of stepping on the ith
stair. You can start from step 0 or step 1, and after paying the cost of a
step, you can climb either one or two steps. Return the minimum cost to reach
the top.

Example:
Input: cost = [10,15,20]
Output: 15

Approach 1 (Memoization):
Recursively find the minimum cost to reach each step and store the computed
results in a DP array so each state is calculated only once, then return the
minimum cost of reaching either of the last two steps.

Time Complexity: O(n)
Space Complexity: O(n)

Approach 2 (Tabulation):
Build the answer from the first step to the last using a DP array, where each
step stores its cost plus the minimum cost of reaching one of the previous two
steps.

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3 (Space Optimized):
Since each step depends only on the previous two steps, keep only their minimum
costs instead of storing the entire DP array, reducing the extra space used.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Only two steps.
- Starting from step 0 is cheaper.
- Starting from step 1 is cheaper.
- All costs are the same.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Memoization --------------------

class Solution {
public:
    int solve(vector<int>& dp, vector<int>& cost, int n) {
        if (n <= 1) return cost[n];

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = cost[n] + min(solve(dp, cost, n - 1),
                                     solve(dp, cost, n - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(solve(dp, cost, n - 1), solve(dp, cost, n - 2));
    }
};

// -------------------- Approach 2: Tabulation --------------------

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[n - 1], dp[n - 2]);
    }
};

// -------------------- Approach 3: Space Optimized --------------------

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = cost[0], prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};