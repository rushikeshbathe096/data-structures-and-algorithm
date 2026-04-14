/*
Problem Statement:
Given an array nums, return true if the array was originally sorted in 
non-decreasing order and then rotated (possibly 0 times). Otherwise, return false.

There may be duplicates in the array.

Example:
Input: nums = [3,4,5,1,2]
Output: true

Constraints:
- 1 <= nums.size()
- Elements can be negative or positive

Approach:
Array is sorted when the order breaks once atmost , to comapare the first and last element will use modulo operator which will make the array circular.

Edge Cases:
- Already sorted array → 0 drops → valid
- All elements same → valid
- More than one drop → invalid

Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i + 1) % n]) cnt++;
        }

        return cnt <= 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << Solution().check(nums) << endl;
    return 0;
}