// LeetCode : https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack
{
    // q1 for main operations and q2 for transfer operations
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
            q1.push(x);
        else
        {
            // First push the x element in the q2, so it will be the front of q2 and when elements transferred back to q1
            // it's the front of q1 as well
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    int pop()
    {
        // Front of q1 to be removed
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        // Front of q1 to be returned
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */