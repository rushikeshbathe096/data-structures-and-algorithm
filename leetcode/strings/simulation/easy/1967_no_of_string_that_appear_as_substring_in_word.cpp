/*
Problem:
Given an array of strings patterns and a string word, return the number of strings in patterns that appear as a substring of word. A substring is a contiguous sequence of characters within a string.

Constraints:
- 1 <= patterns.length <= 100
- 1 <= patterns[i].length <= 100
- 1 <= word.length <= 100
- patterns[i] and word consist of lowercase English letters

Example:
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3

Approach:
Iterate through each string in patterns and use the built-in string::find() function to check whether it exists as a substring of word. If the pattern is found, increment the count. Return the total count after checking all patterns.

Time Complexity: O(n * m * l)
Where n is the number of patterns, m is the length of word, and l is the average length of a pattern. Each find operation may scan the word.

Space Complexity: O(1)
Only a constant amount of extra space is used.

Edge Cases:
- Duplicate patterns. - Pattern equal to the entire word.
- Pattern longer than the word. - No pattern appears as a substring.
- Every pattern appears as a substring.
*/
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(word.find(patterns[i])!=string::npos)cnt++;
        }
        return cnt;
    }
};