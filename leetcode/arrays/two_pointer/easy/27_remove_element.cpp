/*
Problem:
Remove all occurrences of a given value from the array in-place and return the number
of elements that are not equal to the given value. The order of the remaining elements
may be changed, and only the first k elements need to contain the valid values.

Example:
nums = [3,2,2,3], val = 3
Output: 2
Modified nums = [2,2,_,_]

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

Approach:
We use a pointer k to track the position where the next valid element should be placed.
Traverse the array once, and whenever an element is not equal to val, copy it to nums[k]
and increment k. This effectively shifts all required elements to the front while
overwriting the removed values.

Time Complexity: O(n)
The array is traversed only once.

Space Complexity: O(1)
The operation is performed in-place without using any extra space.

Edge Cases:
- Empty array.
- All elements are equal to val.
- No element is equal to val.
- Multiple occurrences of val scattered throughout the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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

    int val;
    cin >> val;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
```
