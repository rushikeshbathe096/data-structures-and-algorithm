/*
Problem:
Given an integer array nums and an integer target, return the indices of the two numbers whose sum equals the target. Each input has exactly one valid solution, and the same element cannot be used twice.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Approach:
Traverse the array once while storing each number and its index in a hash map. For every current element, calculate its required complement (target - current element). If the complement is already present in the hash
map, we have found the required pair, so return their indices. Otherwise, store the current element and continue scanning the array. 

Time Complexity: O(n)
We traverse the array only once, and each hash map lookup and insertion takes O(1) on average. Therefore, the overall time complexity is O(n).

Space Complexity: O(n)
In the worst case, the hash map stores every element of the array along with its index, requiring O(n) extra space.

Edge Cases:
- The required pair contains duplicate values (e.g., [3,3]), so the same index
  must not be reused.
- The complement may appear before the current element, so previously seen
  values must be stored in the hash map.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int n2=target-nums[i];
            if(mp.find(n2)!=mp.end()){
                return {mp[n2],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};