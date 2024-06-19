// LeetCode : https://leetcode.com/problems/odd-even-linked-list/

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

// Way - I (Brute Force [Extra Space])
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> v;
        ListNode *temp = head;
        // Push all odd indices to the vector
        while (temp && temp->next)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }

        // In any case last index is not reached
        if (temp)
            v.push_back(temp->val);

        temp = head->next;
        // Push all even indices to the vector
        while (temp && temp->next)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        // In any case last index is not reached
        if (temp)
            v.push_back(temp->val);

        temp = head;
        int i = 0;
        // Assign all vector elements to the Nodes
        while (temp)
        {
            temp->val = v[i++];
            temp = temp->next;
        }
        return head;
    }
};

// Way - II (Constant Space) --> Connect the Links accordingly
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        // Odd will start from head, even will start from next of head
        ListNode *odd = head, *even = head->next, *firstEven = head->next;
        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        // At the end of linking all connections, the last odd node should connect first even, so we'll preserve first even node
        odd->next = firstEven;
        return head;
    }
};