/*
Problem.
Given a number N, return true if and only if it is a confusing number, which satisfies the following condition:

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

 Solution. Obviously, if  a number contains any of 2,3,4,5,7 then it is not confusing.
 But, this is not enough, we will also need to check if the rotated number
 is different from the original number. To rotate, we reverse the number's digits.
 However, when we see 6 we need to replace it with 9 and when we see 9 we need to replace it with 6.
 In the end, we check if we got a new number or not.




*/




class Solution {
public:
    bool confusingNumber(int N) {
        int copy = N;
        int rev = 0;
        while (copy > 0){
            int rem = copy % 10;

            if (rem == 2 || rem == 3 || rem == 4 || rem == 5 || rem == 7)
                return false;
            if (rem == 9)
                rem = 6;
            else if (rem == 6)
                rem = 9;
            rev = 10* rev + rem;
            copy = copy / 10;
        }

        return rev != N ? true : false;

    }
};

/*
Time complexity. The number of digits of a number n is log(n).
Since we are dividing the (copy of the) number by 10 each time
(basically looping over its digits), the time complexity is log(n).
Space complexity. O(1), we did not store anything.
*/
