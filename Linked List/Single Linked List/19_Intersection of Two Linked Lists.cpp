// LeetCode : https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Way - I (Brute Force [Hashing])
/*
Store all nodes of one linked list in a map, now traverse in the second linked list, if any of the node is found in the map, that
one node is the intersection point, if temp goes to null it means there is no intersection point.
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mp;
        ListNode *mover = headA;
        while (mover)
        {
            mp[mover] = mover->val;
            mover = mover->next;
        }

        mover = headB;
        while (mover)
        {
            if (mp.find(mover) != mp.end())
                return mover;
            mover = mover->next;
        }
        return nullptr;
    }
};

// Way - II (Better [Counting])
/*
Find the larger linked list and move the distance of it's pointer d times where d is difference between 2 lengths of Linked Lists.
Then if there is a intersection node, both will be pointing to each other, otherwise any of the node will point to null, so return null.
*/
class Solution
{
    ListNode *findCommonNode(ListNode *head1, ListNode *head2, int diff)
    {
        ListNode *mover1 = head1, *mover2 = head2;
        while (diff--)
            mover1 = mover1->next;

        while (mover1 && mover2)
        {
            if (mover1 == mover2)
                return mover1;
            mover1 = mover1->next;
            mover2 = mover2->next;
        }
        return nullptr;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int count1 = 0, count2 = 0;
        ListNode *mover = headA;
        while (mover)
        {
            count1++;
            mover = mover->next;
        }

        mover = headB;
        while (mover)
        {
            count2++;
            mover = mover->next;
        }

        if (count1 > count2)
            return findCommonNode(headA, headB, count1 - count2);
        else
            return findCommonNode(headB, headA, count2 - count1);
    }
};

// Way - III (Optimal)
/*
If mover1 points to null, point it to head of other linked list and same for mover2. There will be a point where both movers will be
pointing to same node, that will be the first intersection node. This will be due to the fact that firstly, one mover will cover it's
own LL and then it will start to cover the other LL, second mover will first cover it's own LL and then the other one, and due to this
the linked list with larger size will be covered and at one point both will be pointing to same Node. If there's no intersection point
then both will go to null after covering distance of each other.
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *mover1 = headA, *mover2 = headB;
        while (mover1 != mover2)
        {
            mover1 = mover1 == nullptr ? headB : mover1->next;
            mover2 = mover2 == nullptr ? headA : mover2->next;
        }
        return mover1;
    }
};