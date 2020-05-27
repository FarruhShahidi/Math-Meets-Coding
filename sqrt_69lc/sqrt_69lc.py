"""Implement int sqrt(int x).

Compute and return the square root of x,
where x is guaranteed to be a non-negative integer.

Since the return type is an integer,
the decimal digits are truncated and only the integer part of the result is returned.

"""


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0: return 0
        i, j = 1, x
        while i < j:
            mid = (i+j)//2
            if mid * mid <= x < (mid+1) * (mid +1):
                return mid
            elif (mid+1) * (mid + 1) <= x:
                i = mid +1
            else:
                j = mid
        return i
