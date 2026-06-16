/*
Problem:
Remove duplicates from a sorted array in-place such that each unique element appears only once.
Return the number of unique elements k, with the first k positions of the array containing
the unique elements in their original sorted order.

Example:
nums = [1,1,2]
Output: 2
Modified nums = [1,2,_]

Constraints:
1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100

Approach:
We will use two ptr one for tracking modified new index which will acts as size also and another for traversing elements ,we will initialise k to 1 since first element of array is always unqiue so we take as 1 cuz it overwrites the next unique element

Time Complexity: O(n)
The array is traversed once.

Space Complexity: O(1)
The operation is performed in-place without using extra space.

Edge Cases:
- Array contains only one element.
- All elements are identical.
- No duplicate elements are present.
- Multiple consecutive duplicates.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}