// LeetCode : https://leetcode.com/problems/find-peak-element/description/

// Way - I (Brute Force)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || nums[i] > nums[i - 1]) && (i == n - 1 || nums[i] > nums[i + 1]))
                return i;
        }
        return -1;
    }
};

// Way - II (Binary Search)
/*  
Array will be sorted in chunks, either there will be a increasing curve or decreasing curve.
1. Find the curve on mid index.
2. If the curve is increasing, then peak will be on the right side of the curve (Eliminate left side).
3. If the curve is decreasing, then peak will be on the left side of the curve (Eliminate right side).
*/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int left = 1, mid, right = nums.size() - 2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            else if (nums[mid] > nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
