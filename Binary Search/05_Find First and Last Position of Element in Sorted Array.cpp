// LeetCode : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution
{
    int binarySearch(vector<int> &nums, int start, int end, int target, bool firstIndex)
    {
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else
            {
                ans = mid;
                // If we are finding first index of target, move to left side
                if (firstIndex)
                    end = mid - 1;
                // If we are finding last index of target, move to right side
                else
                    start = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans(2);
        // Find first and last index of target
        ans[0] = binarySearch(nums, 0, n - 1, target, true);
        ans[1] = binarySearch(nums, 0, n - 1, target, false);

        return ans;
    }
};