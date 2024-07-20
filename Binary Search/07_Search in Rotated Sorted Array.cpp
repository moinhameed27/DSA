// LeetCode : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/* Find the sorted half and apply binary search on that [Unique Elements] */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // If left half is sorted
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // If right half is sorted
            else
            {
                if (nums[right] >= target && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};