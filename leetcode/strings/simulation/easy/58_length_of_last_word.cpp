/*
LeetCode 8. Length of Last Word

Problem:
Given a string s consisting of words and spaces, return the length of the last word in the string. A word is defined as a maximal substring containing only non-space characters.

Constraints:
- 1 <= s.length <= 10^4
- s consists of only English letters and spaces.
- There will be at least one word in s.

Example:
Input: s = "Hello World"
Output: 5

Approach:
Use a stringstream to split the string into individual words while automatically ignoring extra spaces. Store the extracted words in a vector and return the length of the last word.

Time Complexity: O(n)
Each character of the string is processed once while extracting the words.

Space Complexity: O(n)
Additional space is used to store all extracted words.

Edge Cases:
- Leading or trailing spaces. - Multiple consecutive spaces between words. - String containing only one word. - Last word consisting of a single character.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        string ans=words[words.size()-1];
        return ans.size();
    }
};