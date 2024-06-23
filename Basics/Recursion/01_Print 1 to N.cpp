// GFG : https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

// Correct Order
class Solution
{
public:
    void printNos(int N)
    {
        if (N == 0)
            return;
        printNos(N - 1);
        cout << N << " ";
    }
};

// Reverse Order
class Solution
{
public:
    void printNos(int N)
    {
        if (N == 0)
            return;
        cout << N << " ";
        printNos(N - 1);
    }
};