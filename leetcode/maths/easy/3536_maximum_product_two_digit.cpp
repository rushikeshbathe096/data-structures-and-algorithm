/*
LeetCode 3536. Maximum Product of Two Digits

Problem:
Given a positive integer n, return the maximum product that can be obtained by multiplying any two digits of n. A digit may be used twice only if it appears at least twice in the number.

Constraints:
- 10 <= n <= 10^9

Example:
Input: n = 124 Output: 8

Approach:
Traverse the digits of n and maintain the largest and second largest digits encountered so far. Whenever a larger digit is found, update the two maximums accordingly. After processing all digits, return the product of the two largest digits.

Time Complexity: O(d)
Each digit of n is processed exactly once, where d is the number of digits.

Space Complexity: O(1)
Only two variables are used to track the largest and second largest digits.

Edge Cases:
- Both largest digits are the same (e.g., n = 22).- Digits contain zeros.- Digits are in increasing or decreasing order.
- The largest digit appears multiple times.
*/
class Solution {
public:
    int maxProduct(int n) {
        int max1=0,max2=0;
        while(n){
            long long rem=n%10;
            if(rem>=max1){
                max2=max1;
                max1=rem;
            }
            else if(rem<max1 && rem>max2){
                max2=rem;
            }
            n/=10;
        }
        return max1*max2;
    }
};