// GFG : https://bit.ly/3w9pEIt

/*
Structure of the linked list node is as
struct Node 
{
  int data;
  struct Node * next;
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
}; 
*/

class Solution
{
public:
    // Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        // Empty Linked List
        if (head == nullptr)
            return new Node(x);

        // Store head in temp
        Node *temp = head;
        // Make a new head, with it's next pointing towards temp
        head = new Node(x);
        head->next = temp;
        return head;
    }

    // Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)
    {
        // Empty Linked List
        if (head == nullptr)
            return new Node(x);
        // Store head in temp
        Node *temp = head;
        // Traverse till last element
        while (temp->next != nullptr)
            temp = temp->next;
        // Make a new node with the x given and assign it to the last element's next
        temp->next = new Node(x);
        return head;
    }
};