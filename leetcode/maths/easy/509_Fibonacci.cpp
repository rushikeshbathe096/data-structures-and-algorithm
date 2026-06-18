#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Use an iterative approach with two pointers to store the last two Fibonacci numbers 
and compute the sequence up to n.

Time Complexity: O(n)
Space Complexity: O(1)
Edge Cases:
- n = 0 -> return 0
- n = 1 -> return 1
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().fib(n) << endl;
    return 0;
}
