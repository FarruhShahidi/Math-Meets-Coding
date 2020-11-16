/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
(A,B) is lower left of vertex  and (C, D) is upper right vertex of the first rectangle.

(E,F) is lower left of vertex  and (G, H) is upper right vertex of the second rectangle.


Solution. It is straightforward to compute the areas of the given rectangles.
We need to check if the intersect, if so we subtract the intersected_area from
the sum the areas, otherwise we return the sum of the areas.
Complexity. We are working with total of 8 points so the time and space complexities are O(1). 


*/



#include <cmath>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 =  abs(A - C) * abs(B - D);
        int area2 = abs(E - G) * abs(F - H);

        // width = min(C, G) - max(A, E);
        // height = min(D,H) - max(B, F);
        int intersected_area = 0;
        // check if the rectangles intersect
        if (min(C, G) > max(A, E) && min(D,H) > max(B, F)){

            return area1 - (min(C, G) - max(A, E)) * ( min(D,H) - max(B, F)) + area2;
        }
        //cout << area1 <<' ' <<  area2 <<' '<< intersected_area << endl;
        return area1 + area2;
    }
};
