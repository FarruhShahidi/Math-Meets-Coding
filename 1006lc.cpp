

/*One simple observation is that (N* (N-1))/ (N - 2) = (N**2 - N)/ (N -2) =
(N**2 - 2*N + N - 2 + 2)/ (N - 2) = N + 1 + 2/(N - 2)
So for N > 4 the expression 2/(N - 2), so clumsy factorial gets simplified.
Using this fact we can solve the problem recursively.*/

class Solution {
public:
    int clumsy(int N) {
        // base cases
        if (N == 4) return 7;
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N % 4 == 0) return N + 1;
        else if (N % 4 == 3) return N - 1;
        else return N + 2;

    }
};
/*
Time and space complexities: Becasue of the way we solved the problem
time and space complexities are O(1).
*/
