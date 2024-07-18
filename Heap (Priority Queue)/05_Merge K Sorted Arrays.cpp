// GFG : https://bit.ly/3QLpaAs

// Way - I (Vector)
class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int m = arr.size(), n = arr[0].size();
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                v.push_back(arr[i][j]);
        }
        sort(v.begin(), v.end());
        return v;
    }
};

// Way - II (Priority Queue [Min Heap])
class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int m = arr.size(), n = arr[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                pq.push(arr[i][j]);
        }

        while (!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};