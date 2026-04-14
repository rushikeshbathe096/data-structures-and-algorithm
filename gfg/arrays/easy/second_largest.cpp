/*
Problem Statement:
Given an array of integers, return the second largest element in the array.
If the second largest element does not exist, return -1.

Example:
Input: arr = [1, 8, 7, 56, 90]
Output: 56

Constraints:
- 1 <= arr.size()
- Elements can be negative or positive

Intuition + Approach:
We maintain two variables: first (largest) and second (second largest).
Traverse the array:
- If current element > first → update second = first, first = current
- Else if current element > second and not equal to first → update second

Edge Cases:
- Array with one element → return -1
- All elements same → return -1
- Works with negative numbers as we initialize with INT_MIN

Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int first = INT_MIN, second = INT_MIN;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > first){
                second = first;
                first = arr[i];
            }
            else if(arr[i] > second && arr[i] != first){
                second = arr[i];
            }
        }

        if(second == INT_MIN) return -1;
        return second;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << Solution().getSecondLargest(arr) << endl;
    return 0;
}