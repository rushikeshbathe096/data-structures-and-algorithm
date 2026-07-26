/*
Problem:
Given a string s consisting only of 'a', 'b', and 'c', return the number of substrings that contain at least one occurrence of all three characters.

Example:
Input: s = "abcabc" Output: 10

Approach:
Use a sliding window with two pointers and keep track of the count of 'a', 'b',and 'c' inside the current window. Expand the window until it contains all three characters, then every substring starting from the current left pointer and ending at the current right pointer or beyond is valid, so add (n - r) to the answer. Shrink the window from the left to find more valid substrings.

Time Complexity: O(n)
Each character is visited at most twice, once by the right pointer and once by the left pointer.

Space Complexity: O(1)
Only a few variables are used to store the counts of 'a', 'b', and 'c'.

Edge Cases:
- String contains exactly one valid substring. - All characters are the same.
- Valid substring appears only at the end. - Multiple overlapping valid substrings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        int l=0,r=0;
        int a=0,b=0,c=0;
        while(r<n){
            if(s[r]=='a')a++;
            else if(s[r]=='b')b++;
            else c++;
            while(a>=1 && b>=1 && c>=1){
                cnt+=n-r;
                if(s[l]=='a')a--;
                else if(s[l]=='b')b--;
                else c--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};