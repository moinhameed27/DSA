// GFG : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Way - I (Brute Force [Vector])
class Solution
{
public: 
    queue<int> modifyQueue(queue<int> q, int k)
    {
        vector<int> v;
        while (!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
        reverse(v.begin(), v.begin() + k);
        for (int i = 0; i < v.size(); i++)
            q.push(v[i]);
        return q;
    }
};

// Way - II (Constant Space)
class Solution
{
    void reverse(queue<int> &q, int k)
    {
        if (k == 0)
            return;
        int num = q.front();
        q.pop();
        reverse(q, k - 1);
        q.push(num);
    }

public:
    queue<int> modifyQueue(queue<int> q, int k)
    {
        // When we'll try to reverse first k elements, they'll go to the end of the queue, so we pop and push
        // first n - k elements so that the reversed ones come at the front of the queue
        reverse(q, k);
        int n = q.size() - k;
        while (n--)
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        return q;
    }
};