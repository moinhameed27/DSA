// LeetCode : https://leetcode.com/problems/valid-parentheses/description/

// Way - I
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            // If there's open bracket, push into stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            // Closing Bracket
            else
            {
                // If stack is empty, open bracket can't be closed
                if (st.empty())
                    return false;
                // If brackets matches
                else if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();
                // brackets don't match
                else
                    return false;
            }
        }
        return st.empty();
    }
};

// Way - II
class Solution
{
    bool isPair(char top, char curr)
    {
        // Pair of braces
        return (top == '(' && curr == ')') ||
               (top == '{' && curr == '}') ||
               (top == '[' && curr == ']');
    }

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char curr : s)
        {
            // If stack is not empty, check for cases
            if (!st.empty())
            {
                char top = st.top();
                // If brackets match, remove from stack and go to next bracket
                if (isPair(top, curr))
                {
                    st.pop();
                    continue;
                }
            }
            // Push into stack in case of empty stack
            st.push(curr);
        }
        return st.empty();
    }
};