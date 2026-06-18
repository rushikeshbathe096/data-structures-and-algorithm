```cpp
/*
Problem:
Given an integer array nums, return the average of all numbers
that are both even and divisible by 3. If no such number exists,
return 0.

Example:
Input:
nums = [1, 3, 6, 10, 12, 15]

Output:
9

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 1000

Approach:
Traverse the array and check if a number is divisible by 6 (which means it is divisible by both 2 and 3). Add such numbers to the sum and count them. If at least one valid number exists, return sum / count; otherwise, return 0.

Time Complexity: O(n)
Each element is visited exactly once.

Space Complexity: O(1)
Only a few extra variables are used.

Edge Cases:
- No number is divisible by 6, so return 0.
- Only one valid number exists, so its value is the average.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;

        for (int num : nums) {
            if (num % 6 == 0) {
                sum += num;
                cnt++;
            }
        }

        return (cnt == 0) ? 0 : sum / cnt;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.averageValue(nums) << endl;

    return 0;
}
```
