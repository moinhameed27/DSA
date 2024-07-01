/*
class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr) {}
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

/*
Problem:
Given a singly linked list, rearrange it such that the converted list should be of the form a < b > c < d > e < f…
Where a, b, c … are consecutive data nodes of the linked list.
Function prototype: void zigzagList(Node * head);
Sample run:
Input: 11->15->20->5->10
Output: 11->20->5->15->10
*/

void zigzagPattern()
{
    Node *mover = head, *prevNode = nullptr;
    int count = 0;
    while (mover)
    {
        count++;
        if (count % 2 == 0)
        {
            if (mover->data < prevNode->data)
                swap(mover->data, prevNode->data);
            if (mover->next && mover->data < mover->next->data)
                swap(mover->data, mover->next->data);
        }
        prevNode = mover;
        mover = mover->next;
    }
}