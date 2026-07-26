/*
Problem:
Given an integer array nums, return an array answer where answer[i] is equal to the product of all elements of nums except nums[i], without using division and in O(n) time.

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Approach:
Create two arrays: a prefix array and a suffix array. The prefix array stores the product of all elements before the current index, while the suffix array stores the product of all elements after the current index. For each position, 
multiply the corresponding prefix and suffix products to obtain the product of all elements except the current one.

Time Complexity: O(n)
We make three linear traversals of the array: one to build the prefix array, one to build the suffix array, and one to compute the final answer. Hence, the overall time complexity is O(n).

Space Complexity: O(n)
Two additional arrays, prefix and suffix, each of size n, are used to store intermediate products. Apart from the output array, these require O(n) extra space.

Edge Cases:
- Array contains exactly two elements. - Array contains one or more zeros. - Array contains negative numbers. - All elements are the same.
- Product of prefixes and suffixes fits within a 32-bit integer as guaranteed.

Note:
This solution uses O(n) extra space. 
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        vector<int>ans(n);
        int first=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        int last=1;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};