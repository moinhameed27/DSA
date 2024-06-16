/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        // Head will always point to the first element of the arrau
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            // Mover's next will point to next element
            mover->next = temp;
            // Mover will move to the next element
            mover = temp;
        }
        return head;
    }
};