/*
Problem. Alex and Lee play a game with piles of stones.
There are an even number of piles arranged in a row, and each pile has a positive integer number of stone piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

Note : the length of piles is even and the sum of the piles is odd.

Solution.  The fact that the length of piles is even and the sum(piles) is odd implies that  one of the numbers a[0] + a[2] + ....  and a[1] + a[3] + ... is larger.
Let us assume that the former is larger. Alex starts from the left. If Lee chooses left, Alex will also choose left. If Lee chooses right, Alex also chooses right. This way Alex is able to choose a[0] + a[2] + .... Therefore, return True

Note: this problem can also be solved with dynamic programming.




*/


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/* Time and space complexities: O(1).
*/
