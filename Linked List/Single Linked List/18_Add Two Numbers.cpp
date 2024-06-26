// LeetCode : https://leetcode.com/problems/add-two-numbers/

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *num1 = l1, *num2 = l2;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *mover = dummyNode;
        int carry = 0;
        while (num1 || num2)
        {
            // Add carry, num1 node value and num2 node value to sum
            int sum = carry;
            if (num1)
                sum += num1->val;
            if (num2)
                sum += num2->val;
            // Make a new Node of value without carry and point it to mover's next
            mover->next = new ListNode(sum % 10);
            // Store the carry to add it to next sum
            carry = sum / 10;
            // Pass the mover to next node
            mover = mover->next;
            // If nodes are not null, keep traversing
            if (num1)
                num1 = num1->next;
            if (num2)
                num2 = num2->next;
        }
        // At the end, if traversal ends but there's still some carry, make a new node, store the carry in it and link the mover's next to this new Node
        if (carry)
            mover->next = new ListNode(carry);

        // Dummy Node's next will be storing the head of this new Linked List
        return dummyNode->next;
    }
};