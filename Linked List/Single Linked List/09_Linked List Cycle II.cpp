// LeetCode : https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Way - I (Brute Force [Map])
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *temp = head;
        // Store the nodes to keep track of them
        unordered_map<ListNode *, int> mp;

        while (temp)
        {
            // If a node is found in the map, it's the starting node of the loop
            if (mp.find(temp) != mp.end())
                return temp;
            mp[temp] = 1;
            temp = temp->next;
        }
        // If temp reaches nullptr, return null as there is no cycle
        return nullptr;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // Fast will move two steps and slow will move one
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            // If both pointers match, means there is a cycle
            if (slow == fast)
            {
                // Start slow from the head and move both pointers one step
                slow = head;
                // There will be a point when both pointers will be at the same node, that will be start of the loop
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        // If temp reaches nullptr, there's no cycle, return null
        return nullptr;
    }
};


/*
-----------------------------------------------------------------------------------------------------------------
Node = {3, 0, 2, 4}, 4 is connected to 0
Two Pointers:
1. Slow and Fast pointers, Fast moves two steps and Slow moves one step, If there is a cycle, they will meet at some point.
2. Start slow from head and fast from meeting point, move both one step, they will meet at the start of the cycle

slow = 3, head = 3
slow = 0, fast = 2
slow = 2, fast = 0
slow = 4, fast = 4 (meet)
* Find the starting node (start slow from head)
slow = 3, fast = 4
slow = 0, fast = 0 (meet - starting node)
*/