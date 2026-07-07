/*
Problem:
Alice and Bob take turns removing an entire pile of stones from either the
beginning or the end of the array. Both play optimally, Alice moves first,
and the total number of stones is odd. Return true if Alice wins.

Example:
Input: piles = [5,3,4,5]
Output: true

Approach:
Since the number of piles is even and the total number of stones is odd, Alice
can always choose either all even-indexed or all odd-indexed piles, whichever
has the larger total, guaranteeing she collects more stones than Bob, so the
answer is always true.

Time Complexity: O(1)
Space Complexity: O(1)

Edge Cases:
- Minimum number of piles.
- Large pile values.
- Any valid even-length array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};