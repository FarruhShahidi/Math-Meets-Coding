/* Problem. You are given two jugs with capacities x and y litres.
There is an infinite amount of water supply available.
You need to determine whether it is possible to measure exactly z litres using these two jugs.

Solution. The main idea is that you can measure exactly z litres if and only if z divides
the gcd of the numbers x and y. This can be proven rigorously but I don't want to go
to the math details. Also, the edge cases should be taken into consideration.

*/



class Solution {
public:
    // defing the gcd function
    int gcd(int a, int b){
        if (b == 0)
            return a;
        else
            return gcd(b, a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z ==0 || z == x  || z == y || z == x + y) // edge cases
            return true;
        if (x == 0 || y == 0 || z > x + y) // edge cases
            return false;
        if (z % gcd(x,y) != 0)  // main idea
            return false;
        return true;

    }
};
/*
Time complexity: We only need to figure out the time complexity for the gcd.
Let us assume gcd(a,b) < f(ab) where f is a function of the product ab to be determined
After one recursion the new pair is b and r = a%b, so we can see that f(ab) = f((ab) / r) + const.
BY iterating this recursive function, we get f(ab) = f((ab) / r**k) + k * const.
We want (ab) / r**k = 1, so r = log(ab) = log(a) + log(b)
So the time complexity if O(log(a) + log (b))
The time complexity of the algorithm is O(log(x) + log(y)).
Space complexity: O(1)

*/
