// GFG : https://www.geeksforgeeks.org/problems/count-digits5716/1

// Given a number N. Count the number of digits in N which evenly divide N.
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

// Count the Number of Digits in a number
// Way - I (Brute Force)
int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

// Way - II (Optimal [Log])
int countDigits(int n)
{

    int count = (int)(log10(n) + 1);
    // The expression (int)(log10(n)+1) calculates the number of digits in 'n' and casts it to an integer.
    // Adding 1 to the result accounts for the case when 'n' is a power of 10, // ensuring that the count is correct.
    return count;
}