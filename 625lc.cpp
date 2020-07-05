/*
Given a positive integer a, find the smallest positive
integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer,
 then return 0.

 Solution. We start dividing the digit divisors of the number starting
 from the largest and put those digits to the end of the output as a digit.
 If a == 1 then it means that the factorization is possible. Otherwise,
 (if a = 121, then a does not change) we return 0.

 Time complexity: The best case senario is when the number does not
 have a digit divisor(not including 1 of course), then the time complexity
 is O(1), otherwise it is equal to the number of digit divisors which
 is at most O(logn).

*/



#include<climits>

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10){return a;}
        long long m = 1, ans = 0;
        for (int i = 9; i > 1; i--){
            while (a % i == 0){
                ans += m * i;
                m *= 10;
                a /= i;
            }
        }
        if ( ans > INT_MAX || a != 1){return 0;}
        return ans;

    }
};
