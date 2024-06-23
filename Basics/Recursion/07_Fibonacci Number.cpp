// LeetCode : https://leetcode.com/problems/fibonacci-number/

// Way - I (Iterative)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int n1 = 0, n2 = 1, next = n1 + n2;
        for (int i = 2; i <= n; i++)
        {
            n1 = n2;
            n2 = next;
            next = n1 + n2;
        }
        return n2;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};
