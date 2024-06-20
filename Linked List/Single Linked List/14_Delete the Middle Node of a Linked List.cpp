// LeetCode : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *temp = head;
        // Count the Size of the Linked List
        int count = 0;
        while (temp)
            count++, temp = temp->next;
        // Middle element of Linked List
        count /= 2;
        temp = head;
        // To go to the previous element of middle, did count - 1
        for (int i = 0; i < count - 1; i++)
            temp = temp->next;
        // Changed the links to remove middle element from the Linked List
        temp->next = temp->next->next;
        return head;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // If head is null or there's only one element in the Linked List
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        // When this loop will end slow will be at the middle element of the Linked List, so we take a Node prev
        // to preserve it's previous element to change links
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Remove the middle element by changing the links
        prev->next = prev->next->next;
        return head;
    }
};