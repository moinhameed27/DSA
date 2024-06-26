// LeetCode : https://leetcode.com/problems/merge-two-sorted-lists/

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

// Way - I (Iterative)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1, *t2 = list2;
        ListNode *dummyNode = new ListNode(-1);
        // Node to traverse through the both Nodes
        ListNode *mover = dummyNode;
        while (t1 && t2)
        {
            // If t1's value is smaller, link mover's next to t1 and pass the t1 to it's next node
            if (t1->val < t2->val)
            {
                mover->next = t1;
                mover = t1;
                t1 = t1->next;
            }
            // Else link mover's next to t2 and pass the t2 to it's next node
            else
            {
                mover->next = t2;
                mover = t2;
                t2 = t2->next;
            }
        }
        // At the end, if any of the node is exhausted and there are still nodes remaining in any of the linked list, link them to combined one
        if (t1)
            mover->next = t1;
        else
            mover->next = t2;
        return dummyNode->next;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};