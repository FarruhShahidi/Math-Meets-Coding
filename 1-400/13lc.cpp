/*
Problem. Convert roman to integer.
Solution. store the roman letters as keys in a map and their corresponding integers values as values.
Loop through the string and ad corresponding values. The only moment where we need to be carefull when
we have something like "IV" in which case we can write IV = -I + V.
So for s[i] if the next number is greater, we deduct from the result instead of adding

*/

#include <string>
#include<vector>
#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> d =
        {{ 'I', 1 }, { 'V', 5 }, { 'X', 10 },{ 'L', 50 }, {'C', 100 },{ 'D', 500 }, { 'M', 1000 } };
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            if ( d[s[i]] < d[s[i + 1]] && i != s.size() - 1)
                res -= d[s[i]];
            else
                res += d[s[i]];
        }
        return res;

    }
};

/*
Time complexity: O(n), where n is the size of the string s.
Space compleaxity: O(1), we only store finite number of letters in a map.*/
