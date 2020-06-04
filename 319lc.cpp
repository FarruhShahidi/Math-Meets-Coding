


/*
If a given number has a prime factor and not divisible by its square
(n = 7*22, n is divisible by 7 but not divisible by 7*7), then after the first round
the number is on and after the 7th round the number is off. So the fate of the number is decided
by the next factor.
If a number is the square if a prime, say n = p*p,
then after round1 it is on, after round p it is off and after round p*p it is back on.
Same logic applies if the number has multiple factors consisting of the squares of primes.
This proves that the number is on if and only if it is a perfect square.
So many squares between 1 and n? 1,4,9,..... till what number?
the number is the floor of sqrt(n)! C++ takes care of the floor automatically,
so we simply return sqrt(n)!



*/

#include <cmath>
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);

    }
};

/*
Time complexity: O(logn), taking square root should take logarithmic time.
Space compleity: O(1).
*/
