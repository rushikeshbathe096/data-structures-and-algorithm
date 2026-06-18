/*
Problem:
Given two sorted arrays nums1 and nums2 with m and n valid elements,merge them into nums1 in non-decreasing order. nums1 has size m + n,with its last n positions reserved for the merge.

Example:
nums1 = [1,2,3,0,0,0], m = 3 nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Approach:
Start from the end of both arrays and compare their largest remaining elements. Since if we start from beginning it can overwrite values and so we cannot recover back. Place the larger one at the last available position in nums1 and move the corresponding pointers backward. After one array is exhausted, copy any remaining elements from nums2.

Time Complexity: O(m + n)
Space Complexity: O(1)

Edge Cases:
- nums2 is empty.
- m = 0.
- Duplicate elements.
- All elements of one array are smaller than the other.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] >= nums2[j]) ? nums1[i--] : nums2[j--];

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n), nums2(n);

    for (int i = 0; i < m; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];

    Solution().merge(nums1, m, nums2, n);

    for (int x : nums1) cout << x << " ";
    cout << endl;

    return 0;
}

