/*
Problem Statement:
Given an array of integers, return the largest element in the array.

Example:
Input: arr = [1, 8, 7, 56, 90]
Output: 90

Constraints:
- 1 <= arr.size()
- Elements can be negative or positive

Intuition + Approach:
We just keep track of the maximum value while traversing the array.
Start with the smallest possible integer and update it whenever we find a bigger element.

Edge Cases:
- Array with one element -> return that element
- All negative numbers -> still works because we start with INT_MIN

Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << Solution().largest(arr) << endl;
    return 0;
}