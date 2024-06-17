// LeetCode : https://leetcode.com/problems/middle-of-the-linked-list/

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
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;

        // Count the number of nodes
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        // Get the middle of the size
        int mid = count / 2 + 1;

        temp = head;
        // Traverse until mid is reached
        while (mid--)
        {
            if (mid > 0)
                temp = temp->next;
        }
        return temp;
    }
};

// Way - II (Optimal) [Tortoise and Hare Algo]
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

/*
-----------------------------------------------------------------------------------------------------------------
The 'slow' pointer advances one node at a time, while the 'fast' pointer moves two nodes at a time.
The Tortoise and Hare algorithm works because the fast-moving hare reaches the end of the list in exactly the same time it 
takes for the slow-moving tortoise to reach the middle. When the hare reaches the end, the tortoise is guaranteed to be 
at the middle of the list.
*/