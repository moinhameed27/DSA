// LeetCode : https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue
{
    // st1 for main operations and st2 for transfer operations
    stack<int> st1, st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        if (st1.empty())
            st1.push(x);
        else
        {
            // Move all elements from st1 to st2
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            // Move x element to st2 so when shifted to st1, it's on the last
            st2.push(x);
            // Move elements from st2 to st1, the front of queue will be at the top
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    int pop()
    {
        // Top element on the stack to be removed
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek()
    {
        // Top element on the stack to be returned
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */