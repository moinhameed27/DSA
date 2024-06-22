// GFG : https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

// LCM and GCD [Euclidean Algorithm]
class Solution
{
public:
    vector<long long> lcmAndGcd(long long A, long long B)
    {
        long long gcd, orgA = A, orgB = B;
        while (A > 0 && B > 0)
        {
            if (A >= B)
                A %= B;
            else
                B %= A;
        }

        if (A == 0)
            gcd = B;
        else
            gcd = A;

        long long lcm = orgA * orgB / gcd;

        return {lcm, gcd};
    }
};

// GCD
// Way - I (Brute Force)
int findGcd(int n1, int n2)
{
    int gcd = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    return gcd;
}

// Way - II (Better)
int findGcd(int n1, int n2)
{
    for (int i = min(n1, n2); i > 0; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
            return i;
    }
    return 1;
}

// Way - III (Optimal [Euclidean Algorithm])
int findGcd(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 %= n2;
        else
            n2 %= n1;
    }
    if (n1 == 0)
        return n2;
    return n1;
}