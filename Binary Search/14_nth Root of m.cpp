// Way - I (Linear Search)
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int left = 1, mid, right = m;
        for (int i = 1; i <= m; i++)
        {
            if (pow(i, n) == m)
                return i;
        }
        return -1;
    }
};

// Way - II (Binary Search)
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int left = 1, mid, right = m;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            long long int power = 1;
            for (int i = 0; i < n; ++i)
            {
                power *= mid;
                if (power > m)
                    break;
            }
            if (power == m)
                return mid;
            else if (power < m)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

// Way - III (Binary Search [Built-In pow function])
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int left = 1, mid, right = m;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (pow(mid, n) == m)
                return mid;
            else if (pow(mid, n) < m)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};