// InterviewBit : https://www.interviewbit.com/problems/nearest-smaller-element/

// Way - I (Brute Force)
vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool isPresent = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                isPresent = true;
                ans.push_back(A[j]);
                break;
            }
        }
        if (!isPresent)
            ans.push_back(-1);
    }
    return ans;
}

// Way - II (Monotonic Stack)
vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> ans;
    for (int num : A)
    {
        while (!st.empty() && st.top() >= num)
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(num);
    }
    return ans;
}
