/*
Problem:
Given an array of strings, group together all strings that are anagrams of each other. The order of the groups and the order of strings within each group do not matter.

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Approach:
For each string, sort its characters to create a canonical form (key). All anagrams produce the same sorted key, so store the index of each string in a hash map using the sorted string as the key. After processing all strings,
traverse the hash map and use the stored indices to collect the original strings into their respective groups.

Time Complexity: O(n × k log k)
There are n strings, and sorting each string of length k takes O(k log k). Building the groups afterward takes O(n), so the overall complexity is O(n × k log k).

Space Complexity: O(n × k)
The hash map stores the sorted key for every string and the indices belonging to each group, requiring O(n × k) space in the worst case.

Edge Cases:
- Empty strings, as "" is an anagram of itself.
- Duplicate strings, which should appear in the same group.
- No two strings are anagrams, so each string forms its own group.

Note:
Instead of storing indices, we can directly store the original strings in the
hash map:
unordered_map<string, vector<string>>.
This simplifies the implementation while keeping the same time and space
complexities.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<string>str=strs;
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<str.size();i++){
            sort(str[i].begin(),str[i].end());
            mp[str[i]].push_back(i);
        }
        for(auto a:mp){
            vector<string>res;
            for(auto i:a.second){
                res.push_back(strs[i]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};