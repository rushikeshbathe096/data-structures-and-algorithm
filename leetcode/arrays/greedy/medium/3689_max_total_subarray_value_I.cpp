/*
Problem:
Given an integer array nums and an integer k, choose exactly k non-empty subarrays.
Subarrays may overlap and the same subarray can be chosen multiple times.

The value of a subarray is:
max(subarray) - min(subarray)

Return the maximum possible total value of the chosen k subarrays.

Example:
nums = [1,3,2], k = 2
Output: 4

Constraints:
1 <= nums.length <= 5 * 10^4 ,0 <= nums[i] <= 10^9
1 <= k <= 10^5

Approach:
Since we can take the same subarray multiple times max value can be found once and multiplied by k gives total value

Time Complexity: O(n)
The array is traversed once to find the maximum and minimum elements.

Space Complexity: O(1)
Only a few extra variables are used.

Edge Cases:
- Array contains only one element, so the answer is 0.
- All elements are equal, resulting in a total value of 0.
- k is large, but repeated selection of the same optimal subarray is allowed.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin(), nums.end());
        long long mini = *min_element(nums.begin(), nums.end());

        return 1LL * k * (maxi - mini);
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> k;

    Solution sol;
    cout << sol.maxTotalValue(nums, k) << endl;

    return 0;
}