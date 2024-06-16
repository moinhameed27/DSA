/*
Unlike Single Linked List, Doubly Linked List moves in both direction with a node pointing to the next node and a
node pointing to the previous node.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node *convertArrayToDLL(vector<int> &vc)
{
    Node *head = new Node(vc[0]);
    Node *prev = head;
    for (int i = 1; i < vc.size(); i++)
    {
        Node *temp = new Node(vc[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    // While temp is valid, means it is not nullptr
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfDLL(Node *head)
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

bool searchElementInDLL(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

// Insertion of a Node : First, Last, k Place, Node

// Insert at the Start
Node *insertFirstNodeInDLL(Node *head, int val)
{
    // Empty Linked List
    if (head == nullptr)
        return new Node(val);

    // Store head in temp
    Node *temp = head;
    // Make a new head, with it's next pointing towards temp and previous be a nullptr
    head = new Node(val, temp, nullptr);
    return head;
}

// Insert Last Node
Node *insertLastNodeInDLL(Node *head, int val)
{
    // Empty Linked List
    if (head == nullptr)
        return new Node(val);
    // Store head in temp
    Node *temp = head;
    // Traverse till last element
    while (temp->next != nullptr)
        temp = temp->next;
    // Make a new node with the val given, it's next will be null and previous will be temp
    temp->next = new Node(val, nullptr, temp);
    return head;
}

// Insert at k index
Node *insertNodeAtKPlaceInDLL(Node *head, int k, int val)
{
    // If Linked List is Empty
    if (head == nullptr)
    {
        // If place is 1, insert at the start
        if (k == 1)
            return new Node(val);
        else
            return head;
    }

    // Only one element in Linked List
    if (head->next == nullptr)
    {
        // If place is 1, insert at the start
        if (k == 1)
        {
            Node *temp = head;
            return new Node(val, temp, nullptr);
        }
        // If place is 2, insert at the second place
        if (k == 2)
        {
            head->next = new Node(val, nullptr, head);
            return head;
        }
        else
            return head;
    }

    int count = 0;
    // Temp will move and prev will keep the previous node
    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        count++;
        // If previous place is reached after which node is to be inserted
        if (count == k - 1)
        {
            // Make a new node and assign it's next to the next of current node
            Node *newNode = new Node(val, temp->next, temp);
            // If K is not the last element, then assign the prev of temp's next to new Node
            if (temp->next != nullptr)
                temp->next->prev = newNode;
            // Assign the next of current node to newNode
            temp->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert Before a Node (1)
Node *insertBeforeAGivenNodeInDLL(Node *head, Node *x, int val)
{
    // If Linked List is Empty
    if (head == nullptr)
        return head;

    // First Element matches the node
    if (head == x)
    {
        Node *temp = head;
        return new Node(val, temp, nullptr);
    }

    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        // If node becomes equal, insert at that place
        if (temp == x)
        {
            // Make a new Node and assign it's next to the current element
            Node *newNode = new Node(val, temp, prev);
            // Previous Node's next node will be the new Node
            prev->next = newNode;
            temp->prev = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert Before a Node(2)
Node *insertBeforeAGivenNodeInDLL(Node *head, Node *x, int val)
{
    Node *prev = x->prev;
    Node *newNode = new Node(val, x, prev);
    prev->next = newNode;
    x->prev = newNode;
    return head;
}

// Deletion of a Node : First, Last, k Place, Node

// Delete First Node
Node *deleteFirstNodeInDLL(Node *head)
{
    // Empty Linked List
    if (head == nullptr)
        return head;
    // 1 Element in the List
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    // Head will move forward after storing itself in temp so that it can be deleted later
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

// Delete Last Node
Node *deleteLastNodeInDLL(Node *head)
{
    // Empty Linked List
    if (head == nullptr)
        return head;
    // 1 Element in the List
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    // Traverse until second last element is reached
    while (temp->next->next != nullptr)
        temp = temp->next;
    // Delete the last Node
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Delete K Place Node
Node *deleteKPlaceNodeInDLL(Node *head, int k)
{
    if (head == nullptr)
        return head;

    // If deletion is to be done at the first place
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }

    int count = 0;
    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        count++;
        // If k index is reached
        if (count == k)
        {
            // Assign the previous node next to the next of current node, in this way both nodes are connected and current can be deleted
            prev->next = temp->next;
            // If temp is the last Node, it's next will be a nullptr and there will be no previous of a nullptr
            if (temp->next != nullptr)
                temp->next->prev = prev;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete a Given Node (1)
Node *deleteAGivenNodeInDLL(Node *head, Node *x)
{
    if (head == nullptr)
        return head;

    // If Node to be deleted is the first one
    if (head == x)
    {
        Node *temp = head;
        delete temp;
        head = head->next;
        head->prev = nullptr;
        return head;
    }

    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        // If value is reached
        if (temp == x)
        {
            // Assign the previous node next to the next of current node, in this way both nodes are connected and current can be deleted
            prev->next = temp->next;
            // If temp is the last Node, it's next will be a nullptr and there will be no previous of a nullptr
            if (temp->next != nullptr)
                temp->next->prev = prev;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete a given Node (2)
Node* deleteAGivenNodeInDLL(Node *head, Node *x)
{
    Node *prev = x->prev;
    Node *next = x->next;
    // Last Node
    if(next == nullptr)
    {
        prev->next = nullptr;
        x->prev = nullptr;
        delete x;
        return head;
    }

    prev->next = next;
    next->prev = prev;
    x->next = x->prev = nullptr;
    delete x;
    return head;
}

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5};
    Node *list = convertArrayToDLL(vc);
    Node *emp = nullptr;

    // printDLL(list);

    // cout << lengthOfDLL(list) << endl;

    // searchElementInDLL(list, 3) == 1 ? cout << "Present" << endl : cout << "Not Present" << endl;

    // 1. Insert First Node
    // list = insertFirstNodeInDLL(list, 0);
    // printDLL(list);

    // 2. Insert Last Node
    // list = insertLastNodeInDLL(list, 6);
    // printDLL(list);

    // 3. Insert at K Place
    // list = insertNodeAtKPlaceInDLL(list, 2, -99);
    // printDLL(list);

    // 4. Insert at specific Node
    // list = insertBeforeAGivenNodeInDLL(list, list->next->next, -99);
    // printDLL(list);

    // 1. Delete First Node
    // list = deleteFirstNodeInDLL(list);
    // printDLL(list);

    // 2. Delete Last Node
    // list = deleteLastNodeInDLL(list);
    // printDLL(list);

    // 3. Delete K Place Node
    // list = deleteKPlaceNodeInDLL(list, 2);
    // printDLL(list);

    // 4. Delete a Node
    // list = deleteAGivenNodeInDLL(list, list->next->next);
    // printDLL(list);

    return 0;
}