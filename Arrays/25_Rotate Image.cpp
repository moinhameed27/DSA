// LeetCode : https://leetcode.com/problems/rotate-image/

// Way - I (Extra Space)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> dupMatrix = matrix;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = dupMatrix[n - j - 1][i];
        }
    }
};

// Way - II (In-Place (Constant Space))
// Take the Transpose of the matrix and then reverse every row
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Optimal way to take the transpose of a matrix in-place
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
