// GFG : https://bit.ly/3V9wY1v

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        // Head will always point to the first element of the array
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
            // Make a new Node
            Node *temp = new Node(arr[i]);
            // Assign it's next as nullptr
            temp->next = nullptr;
            // Assign the prev of temp as the prev Node
            temp->prev = prev;
            // previous node's next will point to the current node
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
};