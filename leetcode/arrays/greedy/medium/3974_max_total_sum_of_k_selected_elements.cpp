/*
Problem:
Given an integer array nums and two integers k and mul, select exactly k elements from nums. For each selected element, either add its value directly to the total sum or multiply it by the current value of mul before adding it. After processing each selected element, mul decreases by 1. Return the maximum possible total sum.

Constraints:
- 1 <= nums.length <= 10^5 - 1 <= nums[i] <= 10^5
- 1 <= k <= nums.length - 1 <= mul <= 10^5

Example:
Input: nums = [6,1,2,9], k = 3, mul = 2
Output: 26

Approach:
Sort the array in descending order so that larger elements are processed first. For each of the k selected elements, use multiplication while the current multiplier is greater than 1, as it always yields a greater contribution than simple addition. Once the multiplier becomes 1 or less, add the remaining selected elements directly to the total sum.

Time Complexity: O(n log n)
Sorting dominates the overall time complexity.

Space Complexity: O(1)
The solution uses only a few extra variables apart from the input array.

Edge Cases:
- mul = 1, so multiplication provides no extra benefit. - k = 1, only one element is selected.
- k = nums.length, all elements must be processed. - Duplicate values in the array.
*/
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        long long sum=0;
        sort(nums.rbegin(),nums.rend());
        int i=0;
        while(k--){
            if(mul>1){
                sum+=1LL*nums[i]*mul;
                i++;
                mul--;
            }
            else{
                sum+=nums[i];
                i++;
            }
        }
        return sum;
    }
};