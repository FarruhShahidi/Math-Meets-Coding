/*

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?


Solution1: The sum of numbers from 0 to n is gievn by n*(n + 1). So to get the missing number
we subtract the sum of array elements from it.
Complexity: Time complexity is O(n) for the sum of the elements.
Space complexity is O(1) if no integer overflow.
Solution2: In order to avoid a possible interger overflow one can use a simple bit manipulation.
Namely, as x^0 = 0 and x^x = 0, then we can xor all the elements in the array with their indices and the length of the array.
The result gives the missing number.
Complexity: Time complexity is linear and space complexity is O(1).
*/

#include <numeric>      // std::accumulate
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    n = nums.size();
    return (n + 1) * n / 2 -
    accumulate(nums.begin(), nums.end(), 0);}
};

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        for (int i = 0; i< n; i++){
            missing ^= i ^ nums[i];

        }
        return missing;

    }
};
