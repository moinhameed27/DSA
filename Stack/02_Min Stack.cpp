// LeetCode :

class MinStack
{
    // Pair to store the top value in it's first and the minimum value till now in it's second
    vector<pair<int, int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        // If stack is empty, push value to both first and second
        if (st.empty())
        {
            pair<int, int> p;
            p.first = p.second = val;
            st.push_back(p);
        }
        // Else, check if last index's top is minimum or current val is minimum
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    void pop()
    {
        // Delete last index of vector
        st.pop_back();
    }

    int top()
    {
        // Last index's first will have the value pushed at last
        return st.back().first;
    }

    int getMin()
    {
        // Last index's second will be having the minimum value pushed till now
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */