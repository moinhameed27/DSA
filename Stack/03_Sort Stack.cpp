// Sort a Stack in Ascending Order

stack<int> sortStack(stack<int> st)
{
    stack<int> holder; 
    while (!st.empty())
    {
        int topOfInput = st.top();
        st.pop();

        // If value in the holder stack is smaller, means topOfInput should go at the bottom of stack
        while (!holder.empty() && holder.top() < topOfInput)
        {
            // Push the values which are smaller
            st.push(holder.top());
            holder.pop();
        }

        holder.push(topOfInput);
    }
    // Values in the temporary stack will be in the ascending order
    return holder;
}