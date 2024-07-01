// LeetCode : https://leetcode.com/problems/rotate-list/

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

// Way - I (Brute Force)
/*
Rotate the list by one k times. Second last node points to nullptr and last node points to head.
*/
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || head->next == nullptr)
            return head;
        ListNode *mover = head;
        int count = 0;
        while (mover)
            count++, mover = mover->next;

        k %= count;
        if (k == 0)
            return head;

        for (int i = 0; i < k; i++)
        {
            mover = head;
            while (mover->next->next)
                mover = mover->next;
            ListNode *lastNode = mover->next;
            mover->next = nullptr;
            lastNode->next = head;
            head = lastNode;
        }
        return head;
    }
};

// Way - II (Count)
/*
1. Count the number of nodes.
2. Traverse the nodes n times where n = count - k.
3. After traversing, n's next will stand at the node which should be at the start of LL.
4. Link it's previous's node to nullptr and it's next to head of the LL and return the new Head.
*/
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || head->next == nullptr)
            return head;
        ListNode *mover = head;
        int count = 0;
        while (mover)
            count++, mover = mover->next;

        k %= count;
        if (k == 0)
            return head;

        mover = head;
        int n = count - k;
        while (--n)
            mover = mover->next;
        ListNode *newHead = mover->next;
        mover->next = nullptr;
        mover = newHead;
        while (mover->next)
            mover = mover->next;
        mover->next = head;
        return newHead;
    }
};

// Way - III (Using Reverse)
/*
1. Reverse all nodes.
2. Reverse first k nodes
3. Reverse nodes after k.
*/
class Solution
{
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode = nullptr;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        ListNode *mover = head;
        int count = 0;
        while (mover)
            count++, mover = mover->next;

        k %= count;
        if (k == 0)
            return head;

        head = reverseList(head);
        mover = head;
        ListNode *prevNode = nullptr;
        while (k--)
            prevNode = mover, mover = mover->next;

        prevNode->next = nullptr;
        ListNode *newHead = reverseList(head);
        ListNode *divisionHead = reverseList(mover);

        mover = newHead;
        while (mover->next)
            mover = mover->next;
        mover->next = divisionHead;
        return newHead;
    }
};
