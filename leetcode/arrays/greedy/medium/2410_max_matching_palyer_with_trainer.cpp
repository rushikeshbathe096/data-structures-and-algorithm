/*
Problem:
Given the ability of each player and the training capacity of each trainer,
match each player with at most one trainer such that the player's ability is
less than or equal to the trainer's capacity. Return the maximum number of
valid matchings.

Example:
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2

Approach:
Sort both the players and trainers, then use two pointers to always match the
least capable unmatched player with the smallest trainer who can train them;
if a trainer cannot train the current player, move to the next trainer,
otherwise form the match and move both pointers, which maximizes the total
number of matchings.

Time Complexity: O(n log n + m log m)
Sorting the players and trainers takes O(n log n + m log m), and the two-pointer
traversal visits each player and trainer at most once.

Space Complexity: O(1)
The algorithm uses only a few extra variables besides the input arrays
(excluding the space used internally by sorting).

Edge Cases:
- Only one player or one trainer.
- More players than trainers.
- More trainers than players.
- No player can be matched.
- Every player can be matched.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, cnt = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return cnt;
    }
};