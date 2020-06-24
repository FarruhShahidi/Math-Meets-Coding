/*
Problem. Angle between hands of a clock.

Given two numbers, hour and minutes.
Return the smaller angle (in degrees) formed between the hour and the minute hand.
Solution. Draw a line from the center to 12. Compute the angles between the line and the minutes
arrow as well as between the hour arrow. Then find the difference of the angles carefully.
More comments inside the code.
*/




#include<algorithms>
#include<math>

using namespace std;



class Solution {
public:
    double angleClock(int hour, int minutes) {
        // let l be the line connecting the center and 12
        hour = hour % 12; // deal with hour = 12, the angle must be 0
        // the angle between the minutes arrow and l, this angle can be > 180
        int minute_angle = minutes * 6;
        //the angle between the hour arrow and l, this angle can also be greater than 180
        double hour_angle = 30 * hour + (double) minutes / 2;
        //The difference between these two angles gives as one of the two angles between the arrows
        double diff = abs(hour_angle - minute_angle);
        //Since we need the smallest angle of the two we need to take the min
        return min(diff, 360- diff);

    }
};
