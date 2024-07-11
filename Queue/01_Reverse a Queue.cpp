// GFG : https://www.geeksforgeeks.org/problems/queue-reversal/1

// Way - I (Brute Force [Vector])
class Solution
{
    void reverse(vector<int> &v)
    {
        int i = 0, j = v.size() - 1;
        while (i < j)
            swap(v[i++], v[j--]);
    }

public:
    queue<int> rev(queue<int> q)
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(q.front());
            q.pop();
        }
        reverse(v);
        for (int i = 0; i < n; i++)
            q.push(v[i]);
        return q;
    }
};

// Way - II (Stack)
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> st;
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        return q;
    }
};

// Way - III (Queue)
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        queue<int> q2;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q.size() - 1; j++)
            {
                int num = q.front();
                q.pop();
                q.push(num);
            }
            q2.push(q.front());
            q.pop();
        }
        return q2;
    }
};

// Way - IV (Recursion)
class Solution
{
    void solve(queue<int> &q)
    {
        if (q.empty())
            return;
        int num = q.front();
        q.pop();
        solve(q);
        q.push(num);
    }

public:
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }
};