// GFG : https://bit.ly/3bZqbGc

// Way - I (Brute Force)
class Solution
{
public:
    vector<int> printLeadersBruteForce(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = i + 1; j < n; j++)
                if (arr[j] > arr[i])
                {
                    flag = false;
                    break;
                }
            if (flag)
                ans.push_back(arr[i]);
        }

        return ans;
    }
};

// Way - II (Optimal)
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        int Max = a[n - 1];
        ans.push_back(Max);
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] >= Max)
            {
                Max = a[i];
                ans.push_back(Max);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
1. Rightmost element will always be a leader
2. Start iterating backwards and if element is greater than the max element in the right side, push to ans
3. At the end, elements will be stored in the reverse order, so to get correct sequence, reverse all elements
*/