// GFG : https://bit.ly/3zWPiBj

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

// Way - I (Brute Force [Checking for every Pair])
/* Time : O(n * n) , Space : O(1)*/
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> vp;
        Node *mover = head;
        while (mover)
        {
            Node *curr = mover->next;
            while (curr)
            {
                if (mover->data + curr->data == target)
                    vp.push_back({mover->data, curr->data});
                curr = curr->next;
            }
            mover = mover->next;
        }
        return vp;
    }
};

// Way - II (Hashing)
/* Time : O(nlogn) , Space : O(n)*/
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        unordered_map<int, int> mp;
        vector<pair<int, int>> vp;
        Node *mover = head;
        while (mover)
        {
            int diff = target - mover->data;
            if (mp.find(diff) != mp.end())
                vp.push_back({diff, mover->data});
            mp[mover->data] = mover->data;
            mover = mover->next;
        }
        sort(vp.begin(), vp.end());
        return vp;
    }
};

// Way - III (Two Pointers)
/* Time : O(n) , Space : O(1) */
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *mover = head;
        vector<pair<int, int>> vp;
        // Getting to the last node
        while (mover->next)
            mover = mover->next;
        Node *left = head, *right = mover;
        // Left and Right should not be equal or cross each other
        while (left != right && left->prev != right)
        {
            if (left->data + right->data < target)
                left = left->next;
            else if (left->data + right->data > target)
                right = right->prev;
            else
            {
                vp.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
        }
        return vp;
    }
};