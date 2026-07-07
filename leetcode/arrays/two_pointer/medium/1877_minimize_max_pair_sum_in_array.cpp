/*
Problem:
Given an even-length array nums, pair up all elements such that the maximum
pair sum is as small as possible, and return this minimized maximum pair sum.

Example:
Input: nums = [3,5,2,3]
Output: 7

Approach:
Sort the array, then always pair the smallest remaining element with the
largest remaining element; this balances each pair's sum, and the largest
pair sum formed during this process is the minimum possible answer.

Time Complexity: O(n log n)
Space Complexity: O(1)

Edge Cases:
- Array contains only one pair.
- All elements are the same.
- Already sorted or reverse sorted array.
- Large differences between smallest and largest elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxsum = 0;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            maxsum = max(maxsum, nums[l] + nums[r]);
            l++;
            r--;
        }

        return maxsum;
    }
};