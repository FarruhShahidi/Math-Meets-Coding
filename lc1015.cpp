/*
We only do the for loop till K + 1.
The simple explanation follows from the Pigeonhole principle.
The possible values of the remainder when divided by K is
1,2,... K - 1. Since we have a range of K numbers, according to the
Pigeonhole principle at least two have the same remainder. Let us assume
that a and b (let's also assume a> b) are those two numbers. Note that
they consist of only 1s so the difference a-b = 11...11000...0000
i.e. consists of ones followed by zeros is divisible by K. Note that K
does not have factors 2 or 5, hence if we remove the zeros in a-b, the new
number is still divisible by K and is less than a. So we found a smaller numbers
divisible by K. This implies that we only need to loop till K + 1.
*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // if K is even or divisible by
        //5 then no number consisting of ones is divisible by K
        if (K % 2 == 0 || K % 5 == 0)
            return -1;

        int N = 0;
        for (auto digit = 1; digit <= K+1; digit++)
        {
            N = (10 * N +1) %K; // the next number consisting of only ones
            // we also want to avoid overflow
            if (N % K == 0)
                return digit;
        }
        return 0;
    }

};
