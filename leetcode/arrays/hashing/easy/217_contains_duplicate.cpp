/*
Problem:
Given an integer array nums, return true if any value appears at least twice
in the array, otherwise return false if all elements are distinct.

Example:
Input: nums = [1,2,3,1]
Output: true

Approach:
Store all elements in a hash set, which automatically keeps only unique values;
if the size of the set is smaller than the size of the original array, some
elements were duplicated, otherwise all elements are distinct.

Time Complexity: O(n)
Space Complexity: O(n)

Edge Cases:
- All elements are unique.
- All elements are the same.
- Only one element in the array.
- Negative numbers are present.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        return st.size() != nums.size();
    }
};