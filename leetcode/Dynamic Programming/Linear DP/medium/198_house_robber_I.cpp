/*
Problem:
You are given an array nums where nums[i] represents the money in the ith
house. You cannot rob two adjacent houses, so return the maximum amount of
money you can rob without alerting the police.

Example:
Input: nums = [2,7,9,3,1]
Output: 12

State:
dp[i] = Maximum money that can be robbed from houses 0 to i without robbing
two adjacent houses.

Approach 1 (Memoization):
For each house, we have two choices: rob it or skip it. If we rob the current
house, we cannot rob the previous one, so we add its money to the answer of
house i-2. If we skip it, we simply take the best answer till house i-1.
Store every computed state in a DP array so each state is solved only once.

Transition:
dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Base Cases:
dp[0] = nums[0]
dp[1] = max(nums[0], nums[1])

Time Complexity: O(n)
Space Complexity: O(n)

Approach 2 (Tabulation):
Create the DP array from left to right using the same state and transition.
Initialize the base cases, then for every house choose the better option
between robbing it or skipping it.

Transition:
dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3 (Space Optimized):
Since each state depends only on the previous two states, keep only those two
values instead of the entire DP array and update them while traversing the
array.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Only one house.
- Two houses.
- All houses have the same amount.
- Large house values.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Memoization --------------------

class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int n) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = max(nums[n] + solve(dp, nums, n - 2),
                           solve(dp, nums, n - 1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(dp, nums, n - 1);
    }
};

// -------------------- Approach 2: Tabulation --------------------

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);

        return dp[n - 1];
    }
};

// -------------------- Approach 3: Space Optimized --------------------

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};