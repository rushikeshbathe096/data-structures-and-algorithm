/*
Problem:
Given an integer array, return the maximum possible product of any three numbers. The array may contain positive, negative, and zero values, so all possible sign combinations must be considered. 

Approach:
The maximum product can come from one of two cases:1. The three largest numbers. or 2. The two smallest (most negative) numbers along with the largest positive number.
This is because the product of two negative numbers is positive, which can produce
a larger result than simply taking the three largest values.

Time Complexity: O(n log n)
- Sorting the array dominates the running time.

Space Complexity: O(1)
- No extra space is used apart from a few variables.

Edge Cases:
-  All numbers are negative.
- Array contains zeros.
- Two large negative numbers produce the maximum product.
- Minimum allowed array size (3 elements).

Key Takeaway:
The maximum product is always the larger of:
(three largest numbers) or (two smallest numbers × largest number).
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[n - 1] * nums[0] * nums[1]);
    }
};