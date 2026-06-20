```cpp
/*
Problem:
Move all 0's to the end of the array while maintaining the relative order of the non-zero elements.
The operation must be performed in-place without using any extra array.

Example:
nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

Approach:
First, find the index of the first zero because every element before it is already in its correct position. If no zero is found, the array does not need any modification. Starting from the next index, whenever a non-zero element is encountered, swap it with the current zero position and increment the zero pointer. This gradually moves all non-zero elements to the front while pushing zeros to the end, preserving the relative order of the non-zero elements.

Time Complexity: O(n)
The array is traversed a constant number of times, and each element is processed at most once after locating the first zero, resulting in linear time.

Space Complexity: O(1)
The algorithm works directly on the input array and uses only a few extra variables.

Edge Cases:
- No zero exists (return immediately).
- All elements are zero or the array has only one element.
- Multiple consecutive zeros or zeros already at the end.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        // Find the first zero
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                i = j;
                break;
            }
        }
        // No zero present
        if (i == -1)
            return;
        // Move non-zero elements forward
        for (int j = i + 1; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    sol.moveZeroes(nums);

    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
```
