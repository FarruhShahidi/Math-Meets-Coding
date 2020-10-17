/*
A web developer needs to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:

The area of the rectangular web page you designed must equal to the given target area.
The width W should not be larger than the length L, which means L >= W.
The difference between length L and width W should be as small as possible.
Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.

Solution: So we need to find a pair of integers with product equal to area.
Since one of the numbers has to be at most sqrt(area) we can loop from sqrt(area) to 1 to find the desider pair.
Time Complexity: sqrt(area). Space Complexity: O(1)
*/


#include <cmath>
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        int n = floor(sqrt(area));
        for (int w = n; w > 0; w--){
            if ( area % w == 0)
            {

                ret.push_back(area / w);
                ret.push_back(w);
                break;
            }

        }
        return ret;

    }
};
