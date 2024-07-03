// GFG : https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

// Function to push an integer into the stack.
void MyStack ::push(int x)
{
    StackNode *newNode = new StackNode(x);
    if (top == nullptr)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top == nullptr)
        return -1;
    else
    {
        int x = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return x;
    }
}