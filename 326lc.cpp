/*

Given an integer, write a function to determine if it is a power of three.
One can solve the problem using a loop. Can you solve the problem without a loop?


*/

/*
A number is a power of three if and only if its 3-base logarithm is an integer
In the below code log3 is calculated using the change of base formula,
i.e. log3(n) = log10(n)/ log10(3)



*/




#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double log3 = log10(n) / log10(3);
        return (log3 - int(log3) == 0) ? true: false;

    }
};
