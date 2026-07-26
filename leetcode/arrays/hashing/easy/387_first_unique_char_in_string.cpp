/*
Problem:
Given a string s, return the index of the first character that appears exactly once. If no such character exists, return -1.

Example:
Input: s = "leetcode"
Output: 0

Approach:
First, count the frequency of every character using a map. Then traverse the string from left to right and return the index of the first character whose frequency is 1. If no such character exists, return -1.

Time Complexity: O(n log k)
Building the map takes O(n log k), where k is the number of distinct characters, because each insertion or lookup in a map takes O(log k). The second traversal also performs O(log k) lookups for each character, so the
overall complexity is O(n log k). Since k ≤ 26 for this problem, this is effectively O(n) in practice.

Space Complexity: O(k)
The map stores the frequency of each distinct character. Since the string contains only lowercase English letters, k ≤ 26, making the extra space constant in practice.

Edge Cases:
- Every character repeats (e.g., "aabb"), so return -1. - The first unique character appears near the end, requiring a complete scan. - The string contains only one character, which is the answer.

Note:
Using `unordered_map<char, int>` or a frequency array of size 26 reduces the time complexity to O(n) on average because lookups and insertions are O(1)
instead of O(log k). For this problem, a frequency array is the most efficient choice since the character set is fixed.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(char a:s)mp[a]++;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1)return i;
        }
        return -1;
    }
};