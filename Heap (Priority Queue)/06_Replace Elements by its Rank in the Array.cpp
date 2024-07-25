// Way - I (Hashing + Sorting)
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        // Duplicate Array
        vector<int> dup(arr.begin(), arr.end());
        unordered_map<int, int> mp;

        // Sorting the Duplicate array
        sort(dup.begin(), dup.end());
        int rank = 1;
        for (int i = 0; i < N; i++)
        {
            // Check for Duplicate Elements, to assign them the same rank
            if (mp.find(dup[i]) == mp.end())
                mp[dup[i]] = rank++;
        }

        // Assigning the Rank to the Original Array
        vector<int> ans(N);
        for (int i = 0; i < N; i++)
            ans[i] = mp[arr[i]];

        return ans;
    }
};

// Way - II (Priority Queue [Min Heap] + Hashing)
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        // Pushing elements into queue
        for (int i : arr)
            pq.push(i);

        int rank = 1;
        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            // If the element is not present in the map, then assign it a rank (For Duplicate elements to have a same rank)
            if (mp.find(top) == mp.end())
                mp[top] = rank++;
        }

        // Assign ranks according to the original array
        vector<int> ans(N);
        for (int i = 0; i < N; i++)
            ans[i] = mp[arr[i]];

        return ans;
    }
};

// Way - III (Priority Queue of Pairs [Min Heap])
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(N);
        // Pushing elements into queue along with their indices
        for (int i = 0; i < N; i++)
            pq.push({arr[i], i});

        // Assigning elements their rank according to their indices stored in the queue
        int rank = 1;
        ans[pq.top().second] = rank;
        int prev = pq.top().first;
        pq.pop();

        while (!pq.empty())
        {
            // If element is not duplicate, then increment the rank and update the previous
            if (pq.top().first != prev)
            {
                prev = pq.top().first;
                rank++;
            }
            // Assign the rank according the index
            ans[pq.top().second] = rank;
            pq.pop();
        }

        return ans;
    }
};