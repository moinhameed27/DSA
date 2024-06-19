// LeetCode : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x, next(next) {}
 * };
 */

// Way - I (Brute Force)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *temp = head;
        int count = 0;
        // Count the length of the Linked List
        while (temp)
            count++, temp = temp->next;

        // k is the node to be deleted
        int k = count - n;

        // If the node to be removed is the head
        if (k == 0)
            return head->next;

        temp = head;
        // Get to the node which is before k
        for (int i = 0; i < k - 1; i++)
            temp = temp->next;

        // Remove the middle link and connect the
        temp->next = temp->next->next;

        return head;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head;
        // Move fast pointer n steps forward
        while (n--)
            fast = fast->next;

        // If fast becomes null, it means that head is the node to be deleted
        if (fast == nullptr)
            return head->next;

        // Move slow and fast by one step until fast reaches last node, and by this time slow will reach the node before which is to be deleted
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // Link the next to of current to next of next
        slow->next = slow->next->next;
        return head;
    }
};

/*
--------------------------------------------------------------------------------------------------------------------------------------
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list. Initially, only fast will move till it crosses N nodes, 
after which both of the pointers will move simultaneously.
2. Traverse the linked list till the fast pointer reaches the last node, that is, the Lth Node, at this stage, the slow pointer 
is guaranteed to be at the (L - N)th node.
3. Remove the link of current slow node with next and point it to the next of next.
*/
