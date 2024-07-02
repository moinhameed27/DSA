// LeetCode : https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        // Store the nodes to keep track of them
        unordered_map<ListNode *, int> mp;

        while (temp)
        {
            // If a node is found in the map, return true
            if (mp.find(temp) != mp.end())
                return true;
            mp[temp] = 1;
            temp = temp->next;
        }
        // If temp reaches nullptr, return false as there is no cycle
        return false;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // If at any point slow and fast pointers are same, it means there is a cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        // IF temp reaches nullptr, there is no cycle
        return false;
    }
};

/*
-----------------------------------------------------------------------------------------------------------------
Node = {3, 0, 2, 4}, 4 is connected to 0
Two Pointers:
1. Slow and Fast pointers, Fast moves two steps and Slow moves one step, If there is a cycle, they will meet at some point.
2. If fast reached nullptr, means there is no cycle

slow = 3, head = 3
slow = 0, fast = 2
slow = 2, fast = 0
slow = 4, fast = 4 (meet)
*/
