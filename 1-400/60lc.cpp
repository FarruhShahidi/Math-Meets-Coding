/*
Problem. Given n, consider all permutations of the set [1,2,3,...,n] listed in
"sorted" i.e., starts "123...n" and ends with "n...321". Return the kth permutation
in this list. The output should be a string.

Solution. One way to solve this problem is to list all the permutations and store
them in a list, then the kth element in that store will give the answer. However,
this solution has O(n!) time and space complexitites.
We can solve the problem better. Note that the first (n -1)! factorial elements start
with a 1, the next (n - 1)! elements start with a 2, and the last (n - 1)! elements
start with n. So if k < (n - 1)! (n = 5, k = 6), then the output starts with 1.
So to get the first digit we divide: ind = (k - 1) // (n - 1)! (why k - 1 and not k?
This is an edge case, for example if n = 3 and k = 2, then the output is "132", but if we divide
k/(n -1)! we get 2, which should not be the first element of the output), then digits[ind] is the
first element o the ouput. The rest of the elements can be found similarly, we decrease n by 1, k by
ind * (n -1)! and do the same procedure. Note that since n is of type int, all we needis to store
the factorials up to 9 and to the best of my knowledge the standard c++ has no library that contains factorial.
*/

#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> fact;
        fact.push_back(1);
        for (int i = 1; i < 10; i++)
            fact.push_back(i * fact[i - 1]);
        vector<char> digits{'1', '2','3','4','5','6','7', '8', '9'};
        for (int i = n; i > 0; i--)
        {
            int ind = (k - 1) / fact[i - 1];
            k -= ind * fact[i - 1];
            ans += digits[ind];
            digits.erase(digits.begin() + ind);
        }
        return ans;

    }

};
/*
Time and space complexities. Assuming  n is of type int, then observe that digits takes O(1) space and therefore
the erase call is also O(1) which makes the total complexity O(n) (for loop only) and the space complexitiy
is O(1). However, if there is
no bound on n, then the time complexity is O(n^2) while the space complexity is O(n).
*/
