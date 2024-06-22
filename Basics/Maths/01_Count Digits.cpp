// GFG : https://www.geeksforgeeks.org/problems/count-digits5716/1

class Solution
{
public:
    int evenlyDivides(int N)
    {
        int temp = N, count = 0;
        while (temp > 0)
        {
            int num = temp % 10;
            // If number is not zero and divisible for N
            if (num != 0 && N % num == 0)
                count++;
            temp /= 10;
        }
        return count;
    }
};