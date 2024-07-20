// LeetCode : https://leetcode.com/problems/binary-search/description/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};