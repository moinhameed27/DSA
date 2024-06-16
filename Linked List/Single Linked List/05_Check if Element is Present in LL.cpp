// GFG : https://bit.ly/3Epriup

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
    bool searchKey(int n, struct Node *head, int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};