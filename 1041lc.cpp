/*
Follow the instructions and change the position and the direction of the robot accordingly.
In the end check if the robot arrived in its original positon or check if the direction changed.
In both cases, the robot is bounded. Otherwise, not bounded.

Time complexity: O(n) as we loop over the instructions once.
Space Complexity: O(1)

*/
/*necessary libraries should be included*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> vect ={0,1};
        vector<int> position = {0,0};
        for (char ch:instructions){
            if (ch == 'G'){
                position[0] += vect[0];
                position[1] += vect[1];
            }
            else if (ch == 'L')

                vect = {-vect[1], vect[0]};
            else
                vect = {vect[1], -vect[0]};

        }
        if (position[0] == 0 && position[1] == 0)
            return true;
        if (vect[0] != 0 || vect[1] != 1)
            return true;
        return false;
    }
};
