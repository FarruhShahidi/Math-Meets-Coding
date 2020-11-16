
/*
Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order,
return the kth factor in this list or return -1 if n has less than k factors.

Solution. This solution is a brute force solution and the time complexity is linear.
However, it is easy to come up with a O(sqrt(n)) solution. To check if i is a factor,
we do not need to have a range from 1 to n for i. We can just check if i * i <= n,
and store the seen factors. This will reduce time complexity to but we would need an
auxiliary space.

*/

class Solution {
public:
    int kthFactor(int n, int k) {
        int count  = 0;
        for (int i = 1; i < n + 1; i++){
            if (n % i == 0)
                count++;
            if (count == k)
                return i;
        }
        return -1;
    }
};
