```cpp
/*
Problem:
Given a string s, reverse only the vowels while keeping all other characters at their original positions.

Example:
Input: "IceCreAm"
Output: "AceCreIm"

Input: "leetcode"
Output: "leotcede"

Constraints:
1 <= s.length <= 3 * 10^5
s consists of printable ASCII characters.

Approach:
Use two pointers, one from the start and one from the end of the string. Move both pointers until they point to vowels, then swap those vowels and continue moving inward. Since all non-vowel characters are skipped, only the vowels get reversed while the remaining characters stay in their original positions. Here, vowel checking is done using `find()` on the string `"AEIOUaeiou"`.

Alternative:
Instead of using `find()` every time, we can create a boolean array of size 256 and mark all vowels as true. Then checking whether a character is a vowel becomes a simple array lookup, avoiding repeated searches while keeping the same two-pointer approach.

Time Complexity: O(n)
Both pointers move only towards the center and each character is processed at most once, so the overall traversal is linear.

Space Complexity: O(n)
A copy of the input string (`ans`) is created and modified in-place, requiring linear extra space.

Edge Cases:
- No vowels present.
- Only vowels or single character.
- Mix of uppercase and lowercase vowels.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string ans=s;
        string a="AEIOUaeiou";
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            //move i till we dont find vowel
            while(i<j && a.find(ans[i])==string::npos)i++;
            while(i<j && a.find(ans[j])==string::npos)j--;
            swap(ans[i],ans[j]);
            i++;
            j--;

        }
        return ans;
    }
};

int main() {
    string s;
    cin>>s;

    Solution sol;
    cout<<sol.reverseVowels(s)<<endl;

    return 0;
}
```
