// Given an integer N, check whether it is prime or not.

// Way - I (Brute Force)
class Solution
{
public:
    int isPrime(int N)
    {
        int divisors = 0;
        for (int i = 1; i <= N; i++)
        {
            if (N % i == 0)
                divisors++;
        }
        // Prime numbers has only 2 divisors (1 and itself)
        return divisors == 2 ? 1 : 0;
    }
};

// Way - II (Optimal)
class Solution
{
public:
    int isPrime(int N)
    {
        if (N == 1)
            return 0;
        for (int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
                return 0;
        }
        return 1;
    }
};