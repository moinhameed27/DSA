// LeetCode : https://leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {
        long reversedNumber = 0;
        while (x != 0)
        {
            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }
        if (reversedNumber > INT_MAX || reversedNumber < INT_MIN)
            return 0;
        return reversedNumber;
    }
};