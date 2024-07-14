// LeetCode : https://leetcode.com/problems/trapping-rain-water/description/

// Find the left maximum and right maximum for each index, minus the height of current building from minimum of left and right maximum.

// Way - I (Brute Force)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int leftMax = 0, rightMax = 0;
            // Finding left maximum
            while (j >= 0)
                leftMax = max(leftMax, height[j--]);
            j = i;
            // Finding right maximum
            while (j < n)
                rightMax = max(rightMax, height[j++]);

            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
};

// Way - II (Better)
class Solution
{
    vector<int> getRightMax(vector<int> &height)
    {
        int n = height.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        return rightMax;
    }

    vector<int> getLeftMax(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        return leftMax;
    }

public:
    int trap(vector<int> &height)
    {
        int n = height.size(), ans = 0;
        // Getting left maximum and right maximum for each building
        vector<int> leftMax = getLeftMax(height);
        vector<int> rightMax = getRightMax(height);

        for (int i = 0; i < n; i++)
            ans += min(leftMax[i], rightMax[i]) - height[i];

        return ans;
    }
};

// Way - III (Stack)
/*
1. Create a stack and iterate through the height array.
2. If the current height is greater than the height at the top of the stack, then we can trap water between the current height and 
the height at the top of the stack.
3. If the current height is smaller than the height at the top of the stack, then we can't trap water.
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int n = height.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                // Distance between current bar and the bar which is greater than the current bar.
                int distance = i - st.top() - 1;
                // Check bounded to height to calculate the water trapped.
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                // Add the trapped water to the answer.
                ans += distance * boundedHeight;
            }
            st.push(i);
        }
        return ans;
    }
};

// Way - IV (Optimal [Two Pointer])
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left <= right)
        {
            // If left building is smaller than right building, then we can trap water only if left building is smaller than leftMax
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            }
            // We can trap water only if right building is smaller than rightMax
            else
            {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
