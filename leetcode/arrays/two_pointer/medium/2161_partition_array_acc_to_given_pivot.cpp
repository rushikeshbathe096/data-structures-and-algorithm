#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Rearrange the array so that elements < pivot come first,followed by == pivot, then > pivot, while preserving order.

Example:
nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]

Constraints:
1 <= nums.length <= 1e5

Approach:
Use two pointers to fill new array and two ptr to traverse the array from left to right and right to left simulataneously then fill the remaining elements with pivot.

Time Complexity: O(n)
The array is traversed once.

Space Complexity: O(n)
An extra array is used to store the result.

Edge Cases:
- All elements equal to pivot.- No elements smaller or greater than pivot.- Multiple pivot occurrences.
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        if(n==1)return nums;
        int l=0,r=n-1;
        vector<int>ans(n);
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot)ans[l++]=nums[i];
            if(nums[j]>pivot)ans[r--]=nums[j];
        }
        while(l<=r)ans[l++]=pivot;
        return ans;
    }
};
int main() {
    int n, pivot;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> pivot;

    Solution sol;
    vector<int> ans = sol.pivotArray(nums, pivot);

    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}