// GFG : https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

class Solution
{
public:
    long long sumOfSeries(long long n)
    {
        if (n == 0)
            return 0;
        long long cube = n * n * n;
        return cube + sumOfSeries(n - 1);
    }
};