// LeetCode : https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Way - I (Brute Force)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> positiveNumbers;
        vector<int> negativeNumbers;
        vector<int> finalArray(size);

        for (int i : nums)
        {
            if (i >= 0)
                positiveNumbers.push_back(i);
            else
                negativeNumbers.push_back(i);
        }

        int p = 0, n = 0;

        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
                finalArray[i] = positiveNumbers[p++];
            else
                finalArray[i] = negativeNumbers[n++];
        }

        return finalArray;
    }
};

// Way - II (Optimal)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> finalArray(size);

        int p = 0, n = 1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                finalArray[p] = nums[i];
                p += 2;
            }
            else
            {
                finalArray[n] = nums[i];
                n += 2;
            }
        }

        return finalArray;
    }
};
