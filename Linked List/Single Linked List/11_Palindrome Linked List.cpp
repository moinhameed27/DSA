// LeetCode : https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> st;
        // Push all values to stack
        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        // Start temp from head again
        temp = head;
        // Check if values from the start and top of stack are same or not
        while (temp)
        {
            if (temp->val != st.top())
                return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

// Way - II (Two Pointers) --> Reverse the second half of LL and compare values
class Solution
{
    // Reverse a Linked List
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *next = head, *prev = nullptr;
        while (next)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // When fast reaches last or second last value, slow will be at the middle of the Linked List
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the half of linked list starting next slow
        slow = reverseLinkedList(slow->next);
        // Compare the values of the two halfs
        ListNode *start = head, *middle = slow;
        while (middle)
        {
            if (start->val != middle->val)
                return false;
            start = start->next;
            middle = middle->next;
        }
        return true;
    }
};

// Way - III (Recursion)
class Solution
{
    bool isPalindrome(ListNode *head, ListNode *&temp)
    {
        if (head == nullptr)
            return true;
        bool check = isPalindrome(head->next, temp) & (head->val == temp->val);
        temp = temp->next;
        return check;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        return isPalindrome(head, head);
    }
};