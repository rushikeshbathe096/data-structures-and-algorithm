```cpp
/*
Problem:
Return the intersection of two integer arrays such that each element appears as many times as
it occurs in both arrays. The order of the result does not matter.

Example:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Approach:
Sort both arrays and use two pointers to compare their elements. If one element is smaller, move its pointer forward because it cannot be part of any future intersection. When both elements are equal, add that value to the answer and move both pointers. Since equal elements are matched one by one, duplicates are automatically included the minimum number of times they appear in both arrays.

Alternative:
We can also use an unordered_map to store the frequency of elements from one array. Then iterate through the second array, and whenever an element has a positive frequency, add it to the answer and decrement its count. This avoids sorting and runs in linear time on average.

Time Complexity: O(m log m + n log n)
Both arrays are sorted first, after which the two-pointer traversal processes each element at most once.

Space Complexity: O(1)
Ignoring the output array, only a few extra variables are used since the sorting is done in-place.

Edge Cases:
- No common elements.
- One array contains more duplicates than the other.
- All elements are common.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int m=nums1.size();
        int n=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])i++;
            else if(nums1[i]>nums2[j])j++;
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<int>nums1(m),nums2(n);

    for(int i=0;i<m;i++) cin>>nums1[i];
    for(int i=0;i<n;i++) cin>>nums2[i];

    Solution sol;
    vector<int>ans=sol.intersect(nums1,nums2);

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

    return 0;
}
```
