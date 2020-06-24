
/*
Problem. Given the coordinates of four points in 2D space,
return whether the four points could construct a square.

Solution. With 4 points we should be able to form 6 distances.
Put them into a vector and let's sort
These 6 distances form a square if and only if
1. The first four distances(the sides) are equal
2. The last two distances(diagonals)
3. Diagonals > sides (otherwise it is a rhombus).
3. first distance is nonzero(we need four distinct points)
This claim is not difficult to prove mathematically.

Time and space complexities. O(1) in both cases since we are working with only four vectors.

Follow up. Given four points return if you can construct a rectangle.
Solution. Similarly to the above, we form the distances and sort them.
We should be able to get at most 3 distinct distance values, otherwise return false.
Let us say distances[0] = w, distances[3] = l, distances[5] = d.
Then, for a rectangle  the followings must be true:
 distances[1] = distances[0], distances[2] = distances[3], distances[4] = distances[5],
 (lengths, widths, and the diagonals are equal in a rectangle)
 w != 0 and w^2 + l^2 = d^2 (Pythagorean theorem). Otherwise we return false.
 Again, this statement can be mathematically proven
 


*/



#include <string>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<float> distances{dist(p1, p2), dist(p1, p3), dist(p1, p4), dist(p2, p3), dist(p2, p4), dist(p3,p4)};
        sort(distances.begin(), distances.end());
        if (distances[0] == 0){return false;}
        if (distances[0] != distances[3]){return false;}
        if (distances[4] != distances[5]){return false;}

        return true;


    }
private:
    float dist(vector<int> &p, vector<int> &q)
    {
        return sqrt(pow((p[0]- q[0]),2)+ pow((p[1] - q[1]), 2));
    }
};
