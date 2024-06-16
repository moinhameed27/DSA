/*
Linked List:
The Linked Lists are linear data structures where the data is not stored at contiguous memory locations so we can only
access the elements of the linked list in a sequential manner. Linked Lists are used to overcome the shortcoming of
arrays in operations such as deletion, insertion, etc.
In a Single Linked List, one memory location called node remembers the address of next node and in this
way all the list of elements is linked. Single Linked List moves only in one direction.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *convertArrayToLinkedList(vector<int> &vc)
{
    // Head will always point to the first element of the list
    Node *head = new Node(vc[0]);
    Node *mover = head;
    for (int i = 1; i < vc.size(); i++)
    {
        Node *temp = new Node(vc[i]);
        // Mover's next will point to next element
        mover->next = temp;
        // Mover will move to the next element
        mover = temp;
    }
    return head;
}

void printLinkedList(Node *head)
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

int lengthOfLinkedList(Node *head)
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

bool searchElementInLinkedList(Node *head, int val)
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

// Insertion of Node : First, k index, x element, Last

// Insert at the Start (Void)
// void insertFirstNodeInLinkedList(Node *&head, int val)
// {
//     if (head == nullptr)
//     {
//         head = new Node(val);
//         return;
//     }
//     Node *temp = head;
//     head = new Node(val, temp);
// }

// Insert at the Start (Returning the head)
Node *insertFirstNodeInLinkedList(Node *head, int val)
{
    // Empty Linked List
    if (head == nullptr)
        return new Node(val);

    // Store head in temp
    Node *temp = head;
    // Make a new head, with it's next pointing towards temp and previous be a nullptr
    head = new Node(val, temp);
    return head;
}

// Insert at the Last (Void)
// void insertLastNodeInLinkedList(Node *&head, int val)
// {
//     if (head == nullptr)
//     {
//         head = new Node(val);
//         return;
//     }
//     Node *temp = head;
//     while (temp->next != nullptr)
//         temp = temp->next;
//     temp->next = new Node(val);
// }

// Insert at the Last (Returning the head)
Node *insertLastNodeInLinkedList(Node *head, int val)
{
    // Empty Linked List
    if (head == nullptr)
        return new Node(val);
    // Store head in temp
    Node *temp = head;
    // Traverse till last element
    while (temp->next != nullptr)
        temp = temp->next;
    // Make a new node with the val given and assign it to the last element's next
    temp->next = new Node(val);
    return head;
}

// Insert at k index
Node *insertNodeAtKPlaceInLinkedList(Node *head, int k, int val)
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

    if (head->next == nullptr)
    {
        // If place is 1, insert at the start
        if (k == 1)
        {
            Node *temp = head;
            return new Node(val, temp);
        }
        // If place is 2, insert at the second place
        if (k == 2)
        {
            head->next = new Node(val);
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
            Node *newNode = new Node(val, temp->next);
            // Assign the next of current node to newNode
            temp->next = newNode;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert at x value
Node *insertNodeAtXValueInLinkedList(Node *head, int x, int val)
{
    // If Linked List is Empty
    if (head == nullptr)
        return head;

    // First Element matches the val
    if (head->data == x)
    {
        Node *temp = head;
        return new Node(val, temp);
    }

    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        // If value becomes equal, insert at that place
        if (temp->data == x)
        {
            // Make a new Node and assign it's next to the current element
            Node *newNode = new Node(val, temp);
            // Previous Node's next node will be the new Node
            prev->next = newNode;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Deletion of Node : First, k index, x element, Last

// Delete First Node
Node *deleteFirstNodeInLinkedList(Node *head)
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
    delete temp;
    return head;
}

// Delete Last Node
Node *deleteLastNodeInLinkedList(Node *head)
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
Node *deleteKPlaceNodeInLinkedList(Node *head, int k)
{
    if (head == nullptr)
        return head;

    // If deletion is to be done at the first place
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
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
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete the x Value Node
Node *deleteXValueNodeInLinkedList(Node *head, int x)
{
    if (head == nullptr)
        return head;

    // If value is placed at the first Node
    if (head->data == x)
    {
        Node *temp = head;
        delete temp;
        head = head->next;
        return head;
    }

    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        // If value is reached
        if (temp->data == x)
        {
            // Assign the previous node next to the next of current node, in this way both nodes are connected and current can be deleted
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5};
    Node *list = convertArrayToLinkedList(vc);
    Node *emp = nullptr;

    // printLinkedList(list);

    // cout << lengthOfLinkedList(list) << endl;

    // searchElementInLinkedList(list, 6) == 1 ? cout << "Present" << endl : cout << "Not Present" << endl;

    // 1. Insert at the Start (Void)
    // insertFirstNodeInLinkedList(list, 0);
    // printLinkedList(list);
    // insertFirstNodeInLinkedList(emp, 0);
    // printLinkedList(emp);

    // 1. Insert at the Start (Returning the head)
    // list = insertFirstNodeInLinkedList(list, 0);
    // printLinkedList(list);
    // emp = insertFirstNodeInLinkedList(emp, 0);
    // printLinkedList(emp);

    // 2. Insert at the End (Void)
    // insertLastNodeInLinkedList(list, 6);
    // printLinkedList(list);
    // insertLastNodeInLinkedList(emp, 0);
    // printLinkedList(emp);

    // 2. Insert at the End (Returning the head)
    // list = insertLastNodeInLinkedList(list, 6);
    // printLinkedList(list);
    // emp = insertLastNodeInLinkedList(emp, 0);
    // printLinkedList(emp);

    // 3. Insert at K Place
    // list = insertNodeAtKPlaceInLinkedList(list, 3, -2);
    // printLinkedList(list);
    // emp = insertNodeAtKPlaceInLinkedList(emp, 1, -2);
    // printLinkedList(emp);

    // 4. Insert at x value
    // list = insertNodeAtXValueInLinkedList(list, 5, 7);
    // printLinkedList(list);
    // list = insertNodeAtXValueInLinkedList(emp, 1, 7);
    // printLinkedList(emp);

    // 1. Delete the First Node
    // list = deleteFirstNodeInLinkedList(list);
    // printLinkedList(list);
    // list = deleteFirstNodeInLinkedList(emp);
    // printLinkedList(emp);

    // 2. Delete the Last Node
    // list = deleteLastNodeInLinkedList(list);
    // printLinkedList(list);
    // list = deleteLastNodeInLinkedList(emp);
    // printLinkedList(emp);

    // 3. Delete the k Place Node
    // list = deleteKPlaceNodeInLinkedList(list, 1);
    // printLinkedList(list);
    // list = deleteKPlaceNodeInLinkedList(emp, 2);
    // printLinkedList(emp);

    // 4. Delete the x Value Node
    // list = deleteXValueNodeInLinkedList(list, 1);
    // printLinkedList(list);
    // list = deleteXValueNodeInLinkedList(emp, 2);
    // printLinkedList(emp);

    return 0;
}