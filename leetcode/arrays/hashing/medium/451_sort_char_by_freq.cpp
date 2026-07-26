/*
Problem:
Given a string s, sort its characters in decreasing order of their frequency. Characters with the same frequency can appear in any order.

Example:
Input: s = "tree" Output: "eert"

Approach:
Count the frequency of every character using a hash map. Store each (character, frequency) pair in a vector and sort the vector in descending order based on frequency using a custom comparator. Finally, construct the answer by appending each character as many times as its frequency.

Time Complexity: O(n + k log k)
Building the frequency map takes O(n), where n is the length of the string. Sorting the k distinct characters takes O(k log k). Constructing the final string again takes O(n). Therefore, the overall complexity is O(n + k log k).

Space Complexity: O(k)
A hash map and a vector are used to store the frequencies of the k distinct characters.

Edge Cases:
- String contains only one character.- All characters are the same. - Every character is unique.
- Multiple characters have the same frequency. - Uppercase and lowercase letters are treated as different characters.
*/
class Solution {
public:
    bool static comp(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);
        string ans="";
        for(auto x:v){
            while(x.second){
                ans+=x.first;
                x.second--;
            }
        }
        return ans;
    }
};