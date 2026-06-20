```cpp
/*
Problem:
Given a 1-indexed sorted array, find the indices of two numbers whose sum equals the target.
There is exactly one valid answer, and the same element cannot be used twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]

Input: numbers = [2,3,4], target = 6
Output: [1,3]

Constraints:
2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
-1000 <= target <= 1000

Approach:
Since the array is already sorted, use two pointers with one at the beginning and the other at the end. If their sum is greater than the target, decrease the right pointer to reduce the sum. If the sum is smaller, increase the left pointer to make it larger. When the sum matches the target, return their 1-based indices. This works because moving pointers in a sorted array eliminates impossible pairs without checking every combination.

Alternative:
A hash map can also solve the problem by storing previously seen values and looking for `target - current`, but it requires O(n) extra space and does not satisfy the constant space requirement.

Time Complexity: O(n)
Each pointer moves only in one direction and every element is visited at most once.

Space Complexity: O(1)
Only a few variables are used apart from the output array.

Edge Cases:
- Target formed by the first and last element.
- Array contains negative numbers.
- Only one valid pair exists (guaranteed by the problem).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int>ans;
        while(i<=j){
            if(nums[i]+nums[j]>target)j--;
            else if(nums[i]+nums[j]<target)i++;
            else {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};

int main() {
    int n,target;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    cin>>target;

    Solution sol;
    vector<int>ans=sol.twoSum(nums,target);

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

    return 0;
}
```
