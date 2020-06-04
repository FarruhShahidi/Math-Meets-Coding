/*Given an integer, write a function to determine if it is a power of two.*/


/*The number has to be possitive. The second condition is that
its binary representation should consist of a single 1 followed by zeros
The operation n & (n - 1) removes the leading zero in the binary representation
of n. So below these two conditions checked.*/



class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n>0 && !(n & (n-1));

    }
};

/*Time and space complexities: O(1)*/
