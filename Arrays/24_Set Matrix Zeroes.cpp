// LeetCode : https://leetcode.com/problems/set-matrix-zeroes/

// Way - I (Brute Force)
class Solution
{
    void markRow(vector<vector<int>> &matrix, int i, int m, int n)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
                matrix[i][j] = -999;
        }
    }

    void markCol(vector<vector<int>> &matrix, int j, int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][j] != 0)
                matrix[i][j] = -999;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow(matrix, i, m, n);
                    markCol(matrix, j, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -999)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Way - II (Hashing)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Arrays to keep track of the rows and cols to be marked 0
        vector<int> hashRow(m, 0);
        vector<int> hashCol(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If current element is 0, mark its hashRow and hashCol as 1
                if (matrix[i][j] == 0)
                {
                    hashRow[i] = 1;
                    hashCol[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If any of the hashRow or hashCol is marked 1, it means element is to be marked 0
                if (hashRow[i] == 1 || hashCol[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Way - III (Constant Space)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Variables to check if first row and column is to marked or not at the end of the process
        bool markRow1 = false, markCol1 = false;

        // Check if there is any 0 in the first row -> means it should be marked or not
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
                markRow1 = true;
        }

        // Check if there is any 0 in the first column -> means it should be marked or not
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                markCol1 = true;
        }

        // Traversing matrix other than first row and column, if element found 0, mark it's adjacent first row and column index as 0
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Marking elements as 0s with respect to their first row and column index
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Check if first row is to marked 0 or not
        if (markRow1)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Check if first column is to marked 0 or not
        if (markCol1)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};