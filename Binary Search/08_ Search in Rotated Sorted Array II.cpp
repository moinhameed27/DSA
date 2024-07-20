// LeetCode : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

/* 
Find the sorted half and apply binary search on that [Duplicate Elements] 
1. The only case where we might can't find the sorted half is the one in which left, mid and right are same.
2. In that case, we can't decide which half is sorted, so we can just skip the leftmost element and rightmost element.
3. This will not affect the answer as we are skipping the duplicates only.
*/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            // Shrinking the search space to find the sorted half
            if (nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left++;
                right--;
                continue;
            }
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
        return false;
    }
};