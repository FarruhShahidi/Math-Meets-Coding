/*
Problem. Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Solution 1. Note that any such ugly number can be formed by multiples of 2,3 and 5.
We can keep generating ugly numbers starting from 1,2,3,5..... However, we need to
maintain the order, which can be done by using a heap data structure.
The time complexity for this solution is O(nlogn) as pushin and poping in a heap
takes logarithmic time.

Solution 2. We can keep track of ugly numbers in a list (ugly_list below).
For each prime 2,3 and 5 we have a corresponding indices i, j and k  to generate
the next ugly number. Then we update the index accordinhly. The solution is written
below.
Time and space complexities for Solution 2. Time complexity is O(n) as we loop
from p = 2 to n. We store the list of ugly numbers so the list complexity is O(n).
*/





#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> ugly_list{1};
        for (int p = 2; p <= n; p++)
        {
            int cur_min = min(min(2 * ugly_list[i], 3 * ugly_list[j]), 5 * ugly_list[k]);
            if (cur_min == 2 * ugly_list[i]){i++;}
            if (cur_min == 3 * ugly_list[j]){j++;}
            if (cur_min == 5 * ugly_list[k]){k++;}
            ugly_list.push_back(cur_min);

        }
        return ugly_list[n - 1];

    }
};
