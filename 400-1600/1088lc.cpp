/*

Probelem. We can rotate digits by 180 degrees to form new digits.
When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively.
When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees
 becomes a different number with each digit valid.
 (Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive


Solution. First note that confusing number can only be built from the digits 0,1,6,8,9.
But, this is not a sufficent condition to be a confusing number. We also need to check
that the number is different than its reversed number.
To do so, we define an addiional backtrack function, which basically starts from 0 and
starts adding the next possible confusing number. In each step we will also need to update the
reversed number.

*/

class Solution {
public:
    int count = 0;
    long long maxN;
    int backtrack(long num, long rev, long size)
    {
        int valid_digits[5] = {0,1,6,8,9};
        unordered_map<int, int> mirror = {{0,0}, {1,1}, {6,9}, {8,8}, {9,6}};

        if (num != rev)
            count++;
        for (auto digit:valid_digits){
            if (digit == 0 && num == 0)
                continue;
            if (num * 10 + digit <= maxN)
                backtrack(10 * num + digit, mirror[digit] * size + rev, 10 * size);
        }
        return count;
    }
    int confusingNumberII(int N) {
        this -> maxN = N;
        return backtrack(0,0,1);




    }
};

/*
Time compecity: With the auxiliary function, we can check whether a number is confusing in
O(1) time, now we need to calculate how many times we call this functin.
The function check all numbers less than N which can be formed from the valid digits.
this number is roughly  5*log(N/ 2) + 5*log((N - 1)/2) +.. 5* log(1/2) which is O(log(N!)/ (2^N)), which
is by the Striling formula(https://en.wikipedia.org/wiki/Stirling%27s_approximation) is roughly
O(nlogn - n). This is an upper bound which might be improved.
Space complexity: O(1) the mirror map and the valid_digits only store 5 elements each.
*/
