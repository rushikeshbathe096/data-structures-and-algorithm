#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Distance to the Target Element (LeetCode 1848)
Topic: Arrays
Difficulty: Easy

Description:
You are given an array, a target value, and a starting index.
Find the smallest distance between the start index and any index
where the target appears.

Approach:
Iterate through the array ,initialize a variable to store the minimum distance, and update it whenever find the target.

Time Complexity: O(n)
Space Complexity: O(1)
Edge Cases:
- Target appears multiple times
- Target appears at the start index
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    int target, start;
    cout << "Enter target and start index: ";
    cin >> target >> start;

    int result = s.getMinDistance(nums, target, start);
    cout << "Minimum Distance: " << result << endl;

    return 0;
}