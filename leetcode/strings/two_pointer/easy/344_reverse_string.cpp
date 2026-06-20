```cpp
/*
Problem:
Reverse the given character array in-place without using extra memory.

Example:
Input: s = ['h','e','l','l','o']
Output: ['o','l','l','e','h']

Constraints:
1 <= s.length <= 10^5
s[i] is a printable ASCII character.

Approach:
Instead of creating a new array, we swap characters from both ends of the string. For every index `i` in the first half, swap `s[i]` with `s[n - i - 1]`, where `n - i - 1` is its corresponding position from the end. We only iterate until the middle because after that every pair has already been swapped once, reversing the string in-place with constant extra space.

Time Complexity: O(n)
We process only the first half of the array, performing one swap for each pair of characters, so the total work is proportional to the size of the string.

Space Complexity: O(1)
The reversal is done directly in the input array using only a few variables.

Edge Cases:
- Single character string.
- Odd-length string (middle character remains unchanged).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<char> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    Solution sol;
    sol.reverseString(s);

    for (char c : s)
        cout << c << " ";
    cout << endl;

    return 0;
}
```
