/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

// Way - I (Stack)
class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        Node *temp = head;
        stack<int> st;
        // Push all values to the stack
        while (temp)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        // Assign head to temp again
        temp = head;
        // Store all values in the temp data according to the sequence of stack
        while (temp)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Way - II (Optimal)
class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *curr = head;
        Node *prev = nullptr;
        while (curr)
        {
            // Preserve the previous node
            prev = curr->prev;
            // Swap the previous and next nodes of current node
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        // At last, Prev will be the second last element, it's previous will be having the head of the list
        return prev->prev;
    }
};