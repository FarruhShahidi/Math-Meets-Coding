/*
For each traling zero the number has a multiple of ten. As 10 = 2* 5,
we need to count the number of 2s and the number of 5s. There are of course more
2s than 5s in the range between 1 and n. Hence we only count the number of 5s and
that will give as the number of trailing zeros.
The number of 5s in n is equal to n / 5 + n / 25 + n / 125  + ...

*/


class Solution {
public:
    int trailingZeroes(int n) {
        int trailing_zeros = 0;
        while (n){
            n /=  5;
            trailing_zeros += n;
        }
        return trailing_zeros;
    }
};

/*
Time complexity: O(log(n)), on each step we divide the number by 5 so it
takes logarithmic time for the while loop to stop
Space complaexity: O(1), no additional memory is used
*/
