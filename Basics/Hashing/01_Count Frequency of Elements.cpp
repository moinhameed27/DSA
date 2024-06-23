// GFG : https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

// Way - I (Array)
class Solution
{
public:
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        vector<int> vc(P, 0);
        for (int i = 0; i < N; i++)
            vc[arr[i] - 1]++;
        for (int i = 0; i < N; i++)
        {
            if (i >= P)
                arr[i] = 0;
            else
                arr[i] = vc[i];
        }
    }
};

// Way - II (Map)
class Solution
{
public:
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < N; i++)
        {
            arr[i] = mp[i + 1];
        }
    }
};