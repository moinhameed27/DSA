// LeetCode : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// Way - I
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, mid, right = nums.size() - 1;
        int ans = INT_MAX;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            // If right half is sorted, take out the minimum element from there and eliminate the right half
            if (nums[mid] <= nums[right])
            {
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
            // Else eliminate the left half
            else
                left = mid + 1;
        }
        return ans;
    }
};

// Way - II
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, mid, right = nums.size() - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            // If right half is sorted, take the minimum and eliminate the half after mid
            // This will ensure that left is always standing at the minimum number
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};