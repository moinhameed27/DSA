// LeetCode : https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int> ans;

        // Loop runs until whole matrix is traversed in spiral manner
        while (left <= right && top <= bottom)
        {
            // Left --> Right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Top --> Bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            // Right --> Left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Bottom --> Top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};