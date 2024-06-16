// GFG : https://bit.ly/3Po7tpf

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {

        Node *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
