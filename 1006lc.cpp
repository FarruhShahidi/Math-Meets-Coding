/*
Normally, the factorial of a positive integer n is the product of all positive integers
less than or equal to n.
For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.

We instead make a clumsy factorial: using the integers in decreasing order,
we swap out the multiply operations for a fixed rotation of operations: multiply (*),
divide (/), add (+) and subtract (-) in this order.

For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
 However, these operations are still applied using the usual order of operations of
 arithmetic: we do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

Additionally, the division that we use is floor division such that 10 * 9 / 8 equals 11.
  This guarantees the result is an integer.

Implement the clumsy function as defined above: given an integer N,
it returns the clumsy factorial of N.*/

/*O ne simple observation is that (N* (N-1))/ (N - 2) = (N**2 - N)/ (N -2) =
(N**2 - 2*N + N - 2 + 2)/ (N - 2) = N + 1 + 2/(N - 2)
So for N > 4 the expression 2/(N - 2), so clumsy factorial gets simplified.
Using this fact we can solve the problem recursively.*/

class Solution {
public:
    int clumsy(int N) {
        // base cases
        if (N == 4) return 7;
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N % 4 == 0) return N + 1;
        else if (N % 4 == 3) return N - 1;
        else return N + 2;

    }
};
