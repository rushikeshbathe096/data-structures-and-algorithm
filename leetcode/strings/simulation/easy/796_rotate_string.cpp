/*
Problem:
Given two strings s and goal, determine whether goal can be obtained by performing any number of left shifts on s.

Example:
Input: s = "abcde", goal = "cdeab"
Output: true

Approach:
First, check if both strings have the same length. If not, a rotation is impossible. Then concatenate s with itself. Every possible rotation of s will appear as a substring of this doubled string. If goal is found inside the concatenated string, then goal is a valid rotation; otherwise, it is not.

Time Complexity: O(n)
Concatenating the string takes O(n), and searching for goal in the doubled string using the built-in find() function takes O(n) on average. Therefore, the overall time complexity is O(n).

Space Complexity: O(n)
An additional string of length 2n is created by concatenating s with itself.

Edge Cases:
- Strings have different lengths.- Both strings are identical.- Rotation by zero positions.- Rotation by n-1 positions.- Strings with repeated characters.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())return false;
        s+=s;
        if(s.find(goal)==string::npos)return false;
        return true;
    }
};