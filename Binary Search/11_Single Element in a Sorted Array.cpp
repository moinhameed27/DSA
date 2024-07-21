// LeetCode : https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// Way - I (Brute Force)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || nums[i] != nums[i - 1]) && (i == n - 1 || nums[i] != nums[i + 1]))
                return nums[i];
        }
        return -1;
    }
};

// Way - II (XOR)
/* XOR of same elements is Zero. Take Xor of all elements, at the end the single element will remain in the answer. */
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};

// Way - III (Binary Search)
/*
nums = {1, 1, 2, 2, 3, 4, 4, 8, 8}
Index: {0  1  2  3  4  5  6  7  8}
Here, the single element is 3.
1. Pairs before single element --> {even idx, odd idx} : Single Element is on the right side (Eliminate Left side)
2. Pairs after single element --> {odd idx, even idx} : Single Element is on the left side (Eliminate right side)
*/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // Separate checks for 0th and n-1th index
        if (n == 1 || nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int left = 1, mid, right = n - 2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Checking the side of the single element with the help of parity of mid
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};