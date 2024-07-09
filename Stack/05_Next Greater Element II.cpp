// LeetCode : https://leetcode.com/problems/next-greater-element-ii/description/

// Monotonic Stack
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        // Start from 2 * n - 1 and follow circular manner to find next greater element for all elements
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();
            if (!st.empty() && i < n)
                ans[i] = st.top();
            st.push(nums[i % n]);
        }
        return ans;
    }
};