// GFG : https://bit.ly/3QD4hHs

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    Node *temp = head;
    // Move until the given position is reached
    for (int i = 0; i < pos; i++)
        temp = temp->next;

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    // If current node is not the last one
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}