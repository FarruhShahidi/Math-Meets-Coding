
/*Implement pow(x, n), which calculates x raised to the power n (xn).
Note:
n is a 32-bit integer
-100.0 < x < 100.0
*/




class Solution {
public:
    double myPow(double x, int n) {

        if (n == 1) return x;
        if (n == 0) return 1;
        if (n == -2147483648) return 1/(x*myPow(x,2147483647));
        // The above step is needed so that the negation below does not overflow
        if (n < 0) return 1/myPow(x, -n);
        if (n % 2 == 0)
            return myPow(x * x, n/2);
        return myPow(x * x, n/2) * x;

    }
};
