// LeetCode : https://leetcode.com/problems/sort-list/

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
    /*
    Built-In find middle function gives correct middle node in case of odd numbers but in case of even numbers it gives the
    next element of middle than the one which is required. Like if n = 4, division should be done 2, 2 but it breaks to 3, 1 so we
    write our function which correctly divides the nodes. Only difference in the code is that initially fast pointer points to next
    of head instead of pointing to head.
    */
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge the two Sorted Linked Lists in the sorted manner
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1, *t2 = list2;
        ListNode *dummyNode = new ListNode(-1);
        // Node to traverse through the both Nodes
        ListNode *mover = dummyNode;
        while (t1 && t2)
        {
            // If t1's value is smaller, link mover's next to t1 and pass the t1 to it's next node
            if (t1->val < t2->val)
            {
                mover->next = t1;
                mover = t1;
                t1 = t1->next;
            }
            // Else link mover's next to t2 and pass the t2 to it's next node
            else
            {
                mover->next = t2;
                mover = t2;
                t2 = t2->next;
            }
        }
        // At the end, if any of the node is exhausted and there are still nodes remaining in any of the linked list, link them to combined one
        if (t1)
            mover->next = t1;
        else
            mover->next = t2;
        return dummyNode->next;
    }

    // Main Recursive Function
    ListNode *Merge_Sort(ListNode *head)
    {
        // If there's no or single element in the list
        if (head == nullptr || head->next == nullptr)
            return head;
        // Finding the Middle element of List to break it down to 2 parts
        ListNode *middle = findMiddle(head);
        // Left side will start from head till middle element
        ListNode *left = head;
        // Right side will start from next element of middle
        ListNode *right = middle->next;
        // Make next of middle to nullptr to break the link between two nodes [Divide them into different Lists]
        middle->next = nullptr;
        // Divide the Left Side until there's only one element
        left = Merge_Sort(left);
        // Divide the Right Side until there's only one element
        right = Merge_Sort(right);
        // Merge both lists in the sorted manner
        return mergeTwoLists(left, right);
    }

public:
    ListNode *sortList(ListNode *head)
    {
        head = Merge_Sort(head);
        return head;
    }
};