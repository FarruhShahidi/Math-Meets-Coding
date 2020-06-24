
/*
Problem. Given a collection of distinct integers, return all possible permutations.
Solution. We solve the problem using backtracking. We start by finding all permutations
that start with with the first element of the collection and this can be done by
calling the backtracking function recursively, then we find all permutations that start
with the second element by swapping the first two elements(we then swap back those elements),
and then we continue this procedure to get all the permutations.
*/


#include<vector>
#include<algorithms>
#include<math>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_permutations;
        backtrack(nums, 0, all_permutations);
        return all_permutations;

    }
private:
    void backtrack(vector<int> &nums, int first, vector<vector<int>> &res)
    {
        int n = nums.size();
        if (first == n){
            res.push_back(nums);
            return;
        }

        for (int i = first; i < n; i++){
            swap(nums[first], nums[i]);
            backtrack(nums, first + 1, res);
            swap(nums[first], nums[i]);
        }
    }
};
/*
Time complexity. Given an array of length n of distinct numbers, there are n! possible permutations,
so the time complexity is O(n!)
Space complexity. If we are considering the output, then O(n!), otherwise O(1).

*/
