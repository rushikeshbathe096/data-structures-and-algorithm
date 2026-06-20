```cpp
/*
Problem:
Return the unique intersection of two integer arrays. Each element in the result should appear
only once, and the order of the returned elements does not matter.

Example:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Approach:
Store all elements of `nums1` in an unordered set for O(1) average lookup. Then iterate through `nums2`, and whenever an element exists in the set and has not already been added to the answer, include it in the result. Using the set avoids checking every element of `nums1`, while the `find()` on the answer vector ensures that each common element is added only once.

Alternative:
Another approach is to sort both arrays and use two pointers. If both pointers point to the same value, add it to the answer while skipping duplicates and move both pointers forward. Otherwise, move the pointer with the smaller value. This avoids hashing but requires sorting the arrays first.

Time Complexity: O(n * m) in the worst case.
Building the unordered set takes O(n), iterating over `nums2` takes O(m), but checking `find(ans.begin(), ans.end(), a)` is linear in the answer size, making the worst-case complexity O(n * m).

Space Complexity: O(n)
The unordered set stores elements from `nums1`, and the answer vector stores only the unique intersection.

Edge Cases:
- No common elements.
- All elements are common but should appear only once.
- Arrays contain many duplicate values.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st(nums1.begin(),nums1.end());
        for(int a:nums2){
            if(st.count(a) && find(ans.begin(),ans.end(),a)==ans.end()){
                ans.push_back(a);
            }
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;

    vector<int>nums1(n),nums2(m);

    for(int i=0;i<n;i++) cin>>nums1[i];
    for(int i=0;i<m;i++) cin>>nums2[i];

    Solution sol;
    vector<int>ans=sol.intersection(nums1,nums2);

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

    return 0;
}
```
