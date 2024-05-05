// LeetCode : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/#:~:text=Input%3A%20nums%20%3D%20%5B2%2C,no%20rotation)%20to%20make%20nums.

/*
If the array is sorted and rotated by some k elmements, to check if it's sorted or not we need to check it's
break points. If the array was sorted originally, then it won't have more than one break point.
*/
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int breakPoints = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
                breakPoints++;
        }
        return (breakPoints <= 1);
    }
};