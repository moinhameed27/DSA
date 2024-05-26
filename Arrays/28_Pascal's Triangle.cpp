// LeetCode (Variation 1) : https://leetcode.com/problems/pascals-triangle/
// LeetCode (Variation 2) : https://leetcode.com/problems/pascals-triangle-ii/
 
/* --> Way - I (Calculating All rows) */
// Variation 1 : Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
class Solution
{
public:
    int generate(int r, int c)
    {
        vector<vector<int>> ans;
        for (int i = 0; i <= r; i++)
        {
            vector<int> currRow(i + 1, 1);
            // Calculating values of all middle elements
            for (int j = 1; j < i; j++)
                currRow[j] = ans[i - 1][j] + ans[i - 1][j - 1];

            ans.push_back(currRow);
        }
        return ans[r - 1][c - 1];
    }
};

// Variation 2 : Given an integer n, return the n-th row of Pascal's triangle.
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        vector<vector<int>> ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> currRow(i + 1, 1);
            // Calculating values of all middle elements
            for (int j = 1; j < i; j++)
                currRow[j] = ans[i - 1][j] + ans[i - 1][j - 1];

            ans.push_back(currRow);
        }
        return ans[rowIndex];
    }
};

// Variation 3 : Given an integer numRows, return the first numRows of Pascal's triangle.
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> currRow(i + 1, 1);
            // Calculating values of all middle elements
            for (int j = 1; j < i; j++)
                currRow[j] = ans[i - 1][j] + ans[i - 1][j - 1];

            ans.push_back(currRow);
        }
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------

/* --> Way - II (nCr Method) */

// Variation 1
int nCr(int r, int c)
{
    int ans = 1;
    for (int i = 0; i < c; i++)
    {
        ans *= (r - i);
        ans /= (i + 1);
    }
    return ans;
}

// Variation 2
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        vector<int> ans(rowIndex + 1, 1);
        long long res = 1;
        for (int i = 1; i < rowIndex + 1; i++)
        {
            res *= (rowIndex + 1 - i);
            res /= i;
            ans[i] = res;
        }
        return ans;
    }
};

// Varitaion 3
class Solution
{
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        vector<int> ans(rowIndex + 1, 1);
        long long res = 1;
        for (int i = 1; i < rowIndex + 1; i++)
        {
            res *= (rowIndex + 1 - i);
            res /= i;
            ans[i] = res;
        }
        return ans;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> currRow = getRow(i);
            ans.push_back(currRow);
        }
        return ans;
    }
};
