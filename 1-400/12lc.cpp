
/*
Problem. Convert an integer to roman. input integer is less than 3999.
Solution. Solution is straightforward. Add converted thousands, then hundrends then, tens and then ones.




*/
#include <string>
#include<vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        // Better keep ints and romans in separately rather than in a map.
        vector<int> ints{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> romans{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string roman;

        for (int i = 0; i < ints.size(); i++){
            while(num >= ints[i]){
                roman += romans[i];
                num -= ints[i];
            }
        }
        return roman;

    }
};
/* Time complexity: O(log(num)). We can discuss this for any number(not necessarily <= 3999).
For each digit of the number, we do finitely many operations, say for 70000, we add 5000, 1000, 1000--
3 steps. Since the number of digits in a number num is log(num), then the time complexity is O(log(num))

Space complexity: O(1). we only store finitely many elements.

*/
