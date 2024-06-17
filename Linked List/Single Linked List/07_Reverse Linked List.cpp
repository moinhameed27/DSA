// LeetCode : https://leetcode.com/problems/reverse-linked-list/

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

// Way - I (Brute Force [Stack])
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> st;
        // Push all valus to stack
        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        // Store all values from stack in stack manner
        temp = head;
        while (temp)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};
// Way - II (Iterative [Optimal])
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *nextNode = head, *prevNode = nullptr;
        while (head)
        {
            // Preserve the next Node of head
            nextNode = head->next;
            // Store the previous node in the next of head
            head->next = prevNode;
            // Previous node will be the current node
            prevNode = head;
            // Head will move forward as next Node will be having next of head
            head = nextNode;
        }
        // Previous Node will be the head of List
        return prevNode;
    }
};

// Way - III (Recursive)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base Case
        if (head == nullptr || head->next == nullptr)
            return head;
        // Call the Recursion for next Node
        ListNode *newHead = reverseList(head->next);
        // Preserve the head's next
        ListNode *front = head->next;
        // Front's next will be pointing to the current node
        front->next = head;
        // At last the current node's next will be pointing to nullptr
        head->next = nullptr;

        return newHead;
    }
};

/*
--------------------------------------------------------------------------------------------------------------------------------------
This recursion continues until it reaches the base case, gradually reversing the linked list starting from the second 
node (node after it) onward. Following the recursion, the function returns the new head of the reversed linked list. This head 
marks the last node of the original list before reversal, now the first node in the reversed sequence.
*/