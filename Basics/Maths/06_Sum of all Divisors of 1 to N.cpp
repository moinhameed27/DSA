// GFG : https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

// Way - I (Brute Force)
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)
                    sum += j;
            }
        }
        return sum;
    }
};

// Way - II (Optimal)
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;

        for (int i = 1; i <= N; i++)
            sum += i * (int(N / i));

        return sum;
    }
};

/*
-------------------------------------------------------------------------------------------------------------------------------------
Dry Run:
--> n = 4
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15

--> n = 5
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
ans = F(1) + F(2) + F(3) + F(4) + F(5)
    = 1 + 3 + 4 + 7 + 6
    = 21
*/