// GFG :

/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        Node *temp = head;
        // If head is to be deleted
        if (x == 1)
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return head;
        }
        // Move till the position is reached
        for (int i = 0; i < x - 1; i++)
            temp = temp->next;

        // Point the previous to the next of current node
        temp->prev->next = temp->next;
        // Point the previous of next to the previous of current node
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        return head;
    }
};