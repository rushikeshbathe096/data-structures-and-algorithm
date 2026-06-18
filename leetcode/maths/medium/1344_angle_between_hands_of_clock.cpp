```cpp
/*
Problem:
Given the current hour and minutes on an analog clock,
return the smaller angle (in degrees) between the hour hand
and the minute hand.

Example:
Input:
hour = 3 minutes = 30

Output:
75

Constraints:
1 <= hour <= 12
0 <= minutes <= 59

Approach:
The hour hand moves 30° per hour (360°/12) and 0.5° per minute (30°/60), while the minute hand moves 6° per minute (360°/60). So, the angle between them is |(30 * hour + 0.5 * minutes) - (6 * minutes)|, which simplifies to |30 * hour - 5.5 * minutes|. Finally, return the smaller angle using min(angle, 360 - angle).

Time Complexity: O(1)
Only a few arithmetic operations are performed.

Space Complexity: O(1)
No extra space is used.

Edge Cases:
- When the clock shows 12, it is treated correctly by the formula.
- Both hands overlap, giving an angle of 0.
- Always return the smaller angle (less than or equal to 180 degrees).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(30 * hour - 5.5 * minutes);
        return min(angle, 360 - angle);
    }
};

int main() {
    int hour, minutes;
    cin >> hour >> minutes;

    Solution sol;
    cout << sol.angleClock(hour, minutes) << endl;

    return 0;
}
```
