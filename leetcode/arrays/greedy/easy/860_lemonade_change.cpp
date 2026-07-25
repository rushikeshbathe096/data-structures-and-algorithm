/*
LeetCode 860. Lemonade Change

Problem:
At a lemonade stand, each lemonade costs $5. Customers pay with either a $5, $10, or $20 bill. Starting with no change, determine whether it is possible to provide the correct change to every customer in the given order.

Constraints:
- 1 <= bills.length <= 10^5 - bills[i] is either 5, 10, or 20

Example:
Input: bills = [5,5,5,10,20] Output: true

Approach:
Maintain the count of available $5 and $10 bills. For each customer: - If they pay with $5, simply increase the count of $5 bills. - If they pay with $10, give back one $5 bill if available. - If they pay with $20, always prioritize giving one $10 bill and one $5 bill   as change. If that is not possible, give three $5 bills. If neither option   is available, return false. If all customers are processed successfully,   return true.

Time Complexity: O(n)
Each customer is processed exactly once.

Space Complexity: O(1)
Only two variables are used to store the counts of $5 and $10 bills.

Edge Cases:
- The first customer pays with $10 or $20.
- Insufficient $5 bills to provide change.
- A $20 bill must be changed using either ($10 + $5) or three $5 bills.
- Multiple consecutive $20 bills.
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0;
        for(int i:bills){
            if(i==5)cnt5++;
            else if(i==10){
                if(cnt5==0)return false;
                cnt5--,cnt10++;
            }
            else{
                if(cnt10<1){
                    if(cnt5<3)return false;
                    cnt5-=3;
                }
                else{
                    if(cnt5<1)return false;
                    cnt10-=1,cnt5-=1;
                }
            }
        }
        return true;

    }
};