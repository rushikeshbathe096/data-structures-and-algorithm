/*
Problem:
You are given an array nums where nums[i] represents the money in the ith
house. The houses are arranged in a circle, so the first and last houses are
adjacent. You cannot rob two adjacent houses. Return the maximum amount of
money you can rob without alerting the police.

Example:
Input: nums = [2,3,2]
Output: 3

State:
dp[i] = Maximum money that can be robbed from the current range of houses
(start to i) without robbing two adjacent houses.

Approach 1 (Memoization):
Since the first and last houses are adjacent, they cannot both be robbed.
Solve the problem twice: once by excluding the first house and once by
excluding the last house. For each range, recursively choose between robbing
the current house (thereby skipping the previous one) or skipping the current
house, while storing computed states to avoid repeated calculations. The larger
of the two answers is the final result.

Transition:
dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Base Cases:
If only one house exists in the range:
dp[start] = nums[start]

If two houses exist in the range:
dp[start+1] = max(nums[start], nums[start+1])

Time Complexity: O(n)
Space Complexity: O(n)

Approach 2 (Tabulation):
Again, solve two linear House Robber problems by excluding either the first or
the last house. Build a DP array for each range using the same transition and
return the larger answer.

Transition:
dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3 (Space Optimized):
Observe that each DP state depends only on the previous two states, so instead
of storing the entire DP array, keep only the last two values while solving
both ranges separately, then return the larger result.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Only one house.
- Two houses.
- All houses have the same amount.
- Maximum amount is obtained by excluding the first house.
- Maximum amount is obtained by excluding the last house.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Memoization --------------------

class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        if (end == start + 1) return max(nums[start], nums[start + 1]);

        if (dp[end] != -1)
            return dp[end];

        int take = nums[end] + solve(dp, nums, start, end - 2);
        int notTake = solve(dp, nums, start, end - 1);

        return dp[end] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n, -1);

        int excludeFirst = solve(dp, nums, 1, n - 1);

        fill(dp.begin(), dp.end(), -1);

        int excludeLast = solve(dp, nums, 0, n - 2);

        return max(excludeFirst, excludeLast);
    }
};

// -------------------- Approach 2: Tabulation --------------------

class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];

        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++)
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n, -1);

        int excludeFirst = solve(dp, nums, 1, n - 1);

        fill(dp.begin(), dp.end(), -1);

        int excludeLast = solve(dp, nums, 0, n - 2);

        return max(excludeFirst, excludeLast);
    }
};

// -------------------- Approach 3: Space Optimized --------------------

class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int excludeFirst = solve(nums, 1, n - 1);
        int excludeLast = solve(nums, 0, n - 2);

        return max(excludeFirst, excludeLast);
    }
};