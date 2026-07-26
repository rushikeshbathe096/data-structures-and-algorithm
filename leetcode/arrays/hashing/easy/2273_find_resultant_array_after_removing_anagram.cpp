/*
Problem:
Given an array of strings, repeatedly remove a word if it is an anagram of the word immediately before it. Return the resultant array after all possible removals.

Example:
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]

Approach:
Start by keeping the first word. Then iterate through the remaining words and compare each word with its previous word in the original array. Two words are anagrams if their sorted forms are identical. If the current word is not an
anagram of the previous word, include it in the answer; otherwise, skip it. This works because removing adjacent anagrams always leads to the same final result regardless of the order of removals.

Time Complexity: O(n × k log k)
There are n words, and for each comparison we sort two strings of length k. Sorting a string takes O(k log k), so the overall complexity is O(n × k log k).

Space Complexity: O(k)
The helper function creates sorted copies of the two strings, requiring O(k) extra space. (The output array is not counted.)

Edge Cases:
- Multiple consecutive anagrams (e.g., ["ab","ba","ab"]), where only the first
  word should remain.- No adjacent words are anagrams, so the original array is returned unchanged.
*/
class Solution {
public:
    bool isanagram(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!isanagram(words[i],words[i-1]))ans.push_back(words[i]);
        }
        return ans;
    }
};