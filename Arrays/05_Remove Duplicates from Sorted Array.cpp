// Coding Ninjas : https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int removeDuplicates(vector<int> &arr, int n)
{
    int duplicates = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            duplicates++;
    }
    return n - duplicates;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// LeetCode : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int duplicates = 0;
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                if (nums[i] == nums[i + 1])
                    duplicates++;
                else
                    temp.push_back(nums[i]);
            }
            else if (i == n - 1)
                temp.push_back(nums[i]);
        }
        nums = temp;
        return n - duplicates;
    }
};