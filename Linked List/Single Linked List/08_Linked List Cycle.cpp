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
