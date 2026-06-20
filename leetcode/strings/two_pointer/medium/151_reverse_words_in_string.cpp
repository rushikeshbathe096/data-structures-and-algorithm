```cpp
/*
Problem:
Reverse the order of words in a string while removing leading, trailing,
and extra spaces between words.

Example:
Input: "the sky is blue"
Output: "blue is sky the"

Input: "  hello world  "
Output: "world hello"

Constraints:
1 <= s.length <= 10^4

Approach:
Use a stringstream to automatically split the string into words while ignoring extra spaces. Store all extracted words in a vector, reverse the vector using two pointers, and finally rebuild the answer by joining the words with a single space. Checking `i > 0` before adding a space prevents an unwanted leading space in the result.

Alternative:
The same task can be done in O(1) extra space by reversing the entire string first and then reversing each individual word while cleaning up extra spaces, but that approach is more implementation-heavy.

Time Complexity: O(n)
Each character is processed a constant number of times while extracting, reversing, and rebuilding the string.

Space Complexity: O(n)
Extra space is used to store the list of words.

Edge Cases:
- Leading or trailing spaces.
- Multiple consecutive spaces.
- Single word input.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); // Treats string like input stream and skips extra spaces
        vector<string>words;
        string word;

        while(ss>>word){ // Extract one word at a time
            words.push_back(word);
        }

        int i=0,j=words.size()-1;
        while(i<=j){
            swap(words[i],words[j]);
            i++,j--;
        }

        stringstream out;
        for(int i=0;i<words.size();i++){
            if(i>0)out<<" "; // Add space only before words after the first
            out<<words[i];
        }

        return out.str();
    }
};

int main() {
    string s;
    getline(cin,s);

    Solution sol;
    cout<<sol.reverseWords(s)<<endl;

    return 0;
}
```
