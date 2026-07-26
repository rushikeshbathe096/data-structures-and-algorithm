/*
Problem:
Given two strings s and t, determine whether t is an anagram of s. Two strings are anagrams if they contain the same characters with the same frequencies, possibly in a different order.

Example:
Input: s = "anagram", t = "nagaram"
Output: true

Approach:
First, check if both strings have the same length. If not, they cannot be anagrams. Then, count the frequency of every character in both strings using two hash maps. If the frequency maps are identical, the strings are anagrams; otherwise, they are not.

Time Complexity: O(n)
We traverse both strings once to build the frequency maps, and comparing the maps takes time proportional to the number of distinct characters. Overall, the complexity is O(n).

Space Complexity: O(1)
Since the strings contain only lowercase English letters, the number of distinct characters is at most 26, so the hash maps use constant extra space. (If the character set were not fixed, the space complexity would be O(k),where k is the number of distinct characters.)

Edge Cases:
- Strings of different lengths.- Both strings are identical.
- Strings with repeated characters.- Strings containing completely different characters.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        return mp1==mp2;
    }
};