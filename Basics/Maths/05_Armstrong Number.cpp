// GFG : https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

/*
Given an integer N, return true it is an Armstrong number otherwise return false.
An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
*/
class Solution
{
public:
    string armstrongNumber(int n)
    {
        int digits = (int)log10(n) + 1;
        int temp = n, sum = 0;
        while (temp > 0)
        {
            int num = temp % 10;
            sum += pow(num, digits);
            temp /= 10;
        }
        return sum == n ? "true" : "false";
    }
};