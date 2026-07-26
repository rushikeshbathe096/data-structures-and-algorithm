/*
Problem:
Given an array of positive integers, select the largest possible subset that can be arranged in the form: [x, x², x⁴, ..., xᵏ, ..., x⁴, x², x] where every value except the middle element must appear twice. Return the maximum possible size of such a subset.

Example:
Input: nums = [5,4,1,2,2] Output: 3

Approach:
Count the frequency of every number using a hash map. Handle the number 1 separately because squaring 1 always gives 1, so we can only use an odd number of 1's. For every other unique number, try to build the longest valid chain by repeatedly squaring the current value. Every intermediate value must appear at
least twice since it appears on both sides of the pattern, while the last value can appear once as the center. If a required value is missing, adjust the length accordingly and stop. Keep the maximum length among all possible starting numbers.

Time Complexity: O(n)
Building the frequency map takes O(n). Although we iterate over all unique numbers, each squaring chain is very short because the values grow exponentially (x, x², x⁴, ...), so the overall complexity is effectively O(n).

Space Complexity: O(n)
An unordered_map is used to store the frequency of each distinct number.

Edge Cases:
- All elements are 1. - Every element is unique. - A chain breaks because a required squared value is missing.
- The last element of the chain appears only once. - Large values where further squaring would overflow or exceed the maximum  value in the array.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int x:nums) mp[x]++;

        long long mx=*max_element(nums.begin(),nums.end());
        int ans=1;
         // Handle 1 separately
        if(mp.count(1))
            ans=max(ans,mp[1]&1?mp[1]:mp[1]-1);

        for(auto &p:mp){
            long long curr=p.first;
            if(curr==1) continue;

            int len=0;

            while(true){
                if(mp[curr]>=2){
                    len+=2;
                    // Prevent overflow or exceeding the maximum value
                    if(curr>mx/curr||curr*curr>mx){
                        len--;
                        break;
                    }
                    curr*=curr;
                }
                else if(mp[curr]==1){
                    len++;
                    break;
                }
                else{
                    len--;
                    break;
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};