// Statement : Given a positive integer, N. Find the factorial of N.
// GFG : https://www.geeksforgeeks.org/problems/factorial5739/1

// Statement : Find all factorial numbers less than or equal to n
// GFG : https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%5B%5D=-1&page=1&query=problemTypefunctionaldifficulty%5B%5D-1page1

// Statement 1
// Way - I (Iterative)
class Solution
{
public:
    long long int factorial(int N)
    {
        long long ans = 1;
        for (int i = 1; i <= N; i++)
            ans *= i;
        return ans;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    long long int factorial(int N)
    {
        if (N == 0 || N == 1)
            return 1;
        return N * factorial(N - 1);
    }
};

// Statement 2
// Way - I (Iterative)
class Solution
{
public:
    vector<long long> factorialNumbers(long long n)
    {
        long long factorial = 1;
        vector<long long> vc;
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
            if (factorial > n)
                break;
            vc.push_back(factorial);
        }
        return vc;
    }
};

// Way - II (Recursive)
class Solution
{
    void factorialHelper(long long n, long long currentFactorial, int currentNumber, vector<long long> &vc)
    {
        if (currentFactorial > n)
            return;
        vc.push_back(currentFactorial);
        factorialHelper(n, currentFactorial * (currentNumber + 1), currentNumber + 1, vc);
    }

public:
    vector<long long> factorialNumbers(long long n)
    {
        vector<long long> vc;
        factorialHelper(n, 1, 1, vc);
        return vc;
    }
};