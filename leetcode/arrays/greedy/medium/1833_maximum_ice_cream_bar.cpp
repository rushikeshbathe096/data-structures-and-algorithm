/*
Problem:
Given an array costs where costs[i] is the price of the ith ice cream bar and
an integer coins representing the available money, return the maximum number
of ice cream bars that can be bought. The bars can be purchased in any order.

Example:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4

Approach:
Sort the ice cream prices in increasing order and keep buying the cheapest bar
while enough coins are available, since buying cheaper bars first allows us to
purchase the maximum possible number of bars.

Time Complexity: O(n log n)
Space Complexity: O(1)

Edge Cases:
- Not enough coins to buy any bar.
- Enough coins to buy all bars.
- Multiple bars have the same cost.
- Only one ice cream bar.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0;
        sort(costs.begin(), costs.end());

        for (int i = 0; i < costs.size(); i++) {
            if (costs[i] > coins) break;
            cnt++;
            coins -= costs[i];
        }

        return cnt;
    }
};