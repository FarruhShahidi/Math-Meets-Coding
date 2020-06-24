/*
Problem. Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

Solution. If N can be written in the above way then for some int n:
n + (n + 1) + ... + (n + i - 1) = N, which can be written as
i*n + i*(i - 1)/ 2 = N.
From this equation we need to find all possible values of n. to solve for n,
the expression (N - i*(i - 1)/ 2) / i must be an integer, which is our criteria.
In addition, we can figure out an upper bound for i, i*(i -1 )< 2*N implies
that i < sqrt(2*N).

Time complexity. The last statement make the time complexity of O(sqrt(N)).
Space complexity. O(1).


*/




#include<vector>
#include<algorithms>
#include<math>

using namespace std;



class Solution {
public:
    int consecutiveNumbersSum(int N) {
        if (N == 1){return 1;}
        int count = 0;
        for ( int i = 1; i< sqrt(2 * N); i++){
            if (( N - ( i * ( i - 1 )/2) ) % i == 0 )
                count++;
        }
        return count;
    }

};
