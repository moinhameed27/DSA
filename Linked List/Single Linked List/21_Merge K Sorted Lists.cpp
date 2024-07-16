// LeetCode : https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Way - I (Brute Force [Vector])
class Solution
{
    ListNode *convertArrayToLL(vector<int> &vc)
    {
        ListNode *head = new ListNode(vc[0]);
        ListNode *mover = head;
        for (int i = 1; i < vc.size(); i++)
        {
            ListNode *newNode = new ListNode(vc[i]);
            mover->next = newNode;
            mover = mover->next;
        }
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        int n = lists.size();
        vector<int> vc;
        for (int i = 0; i < n; i++)
        {
            ListNode *head = lists[i];
            while (head)
            {
                vc.push_back(head->val);
                head = head->next;
            }
        }
        if (vc.empty())
            return nullptr;
        sort(vc.begin(), vc.end());
        ListNode *head = convertArrayToLL(vc);
        return head;
    }
};

// Way - II (Better [Merge two Lists at one time])
class Solution
{
    ListNode *mergeTwoLists(ListNode *t1, ListNode *t2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *mover = dummyNode;
        while (t1 && t2)
        {
            if (t1->val < t2->val)
            {
                mover->next = t1;
                mover = mover->next;
                t1 = t1->next;
            }
            else
            {
                mover->next = t2;
                mover = mover->next;
                t2 = t2->next;
            }
        }
        if (t1)
            mover->next = t1;
        else
            mover->next = t2;
        return dummyNode->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        int n = lists.size();
        ListNode *head = lists[0];
        for (int i = 1; i < n; i++)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }
};

// Way - III (Optimal [Priority Queue])
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

        for (auto head : lists)
        {
            if (head)
                pq.push({head->val, head});
        }

        ListNode *dummyNode = new ListNode(-1);
        ListNode *mover = dummyNode;

        while (!pq.empty())
        {
            mover->next = pq.top().second;
            pq.pop();
            mover = mover->next;
            if (mover->next)
                pq.push({mover->next->val, mover->next});
        }
        return dummyNode->next;
    }
};