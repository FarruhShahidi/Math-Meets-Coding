/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
*******************************************************************
Solution.
If the number is even, obviously divide by 2.
Otherwise, one needs to look at the remainder when divided by 4.
If the remainder is 1, then by subtracting 1, the new number is divisible by
4 so we can replace by the half of that number twice. This makes it faster to reach 1.
Similarly, if the remainder is 3, then we add 1.


*/


class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        if (n == 1) return 0;
        if (n == 3) return 2;
        if (n % 4 == 3) return 1 + integerReplacement(n + 1);
        if ( n % 4 == 1) return 1 + integerReplacement(n-1);

        return 1 + integerReplacement(n / 2);
    }
};

/*Time compleaxity: O(logn). If the number is a power of 2, then
it is easy to see that the time complexity is logarithmic, it is true in general:
if a number is odd, after one replacement it becomes even so we can divide by 2
Space complexity: O(1). We did not store anything.

*/
