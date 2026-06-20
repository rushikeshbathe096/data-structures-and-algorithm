```cpp
/*
Problem:
Given a sorted integer array, return a new array containing the squares of each element,
also sorted in non-decreasing order.

Example:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4

Approach:
The largest square will always come from either the leftmost or the rightmost element because they have the greatest absolute values. Use two pointers at both ends and compare their absolute values, placing the larger square at the end of the answer array and moving the corresponding pointer. Repeat until all positions are filled.

Alternative:
A simpler approach is to square every element first and then sort the resulting array. However, that takes O(n log n) time, whereas the two-pointer approach achieves linear time by taking advantage of the initial sorted order.

Time Complexity: O(n)
Each element is processed exactly once while filling the answer array from back to front.

Space Complexity: O(n)
An additional array of size n is used to store the sorted squares.

Edge Cases:
- All numbers are negative.
- All numbers are non-negative.
- Array contains zero or duplicate values.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=n-1,k=n-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[k--]=nums[i]*nums[i];
                i++;
            }
            else {
                ans[k--]=nums[j]*nums[j];
                j--;
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution sol;
    vector<int>ans=sol.sortedSquares(nums);

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

    return 0;
}
```
