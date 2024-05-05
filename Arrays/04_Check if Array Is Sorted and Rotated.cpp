LeetCode : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/#:~:text=Input%3A%20nums%20%3D%20%5B2%2C,no%20rotation)%20to%20make%20nums.

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

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:

1.
nums[5] = {3, 4, 5, 1, 2}

n = 5;
breakPoints = 0;

--> i = 0;
nums[(0 + 1) % 5] = nums[1]
IF : 3 > 4 (F)

--> i = 1;
nums[(1 + 1) % 5] = nums[2]
IF : 4 > 5 (F)

--> i = 2;
nums[(2 + 1) % 5] = nums[3]
IF : 5 > 1 (T)
breakPoints = 1

--> i = 3;
nums[(3 + 1) % 5] = nums[4]
IF : 1 > 2 (F)

--> i = 4;
nums[(4 + 1) % 5] = nums[0]
IF : 2 > 3 (F)

breakPoints <= 1 (True)



2.
nums[4] = {2, 1, 3, 4}

n = 4;
breakPoints = 0;

--> i = 0;
nums[(0 + 1) % 4] = nums[1]
IF : 2 > 1 (T)
breakPoints = 1

--> i = 1;
nums[(1 + 1) % 4] = nums[2]
IF : 1 > 3 (F)

--> i = 2;
nums[(2 + 1) % 4] = nums[3]
IF : 3 > 4 (F)1

--> i = 3;
nums[(3 + 1) % 4] = nums[0]
IF : 4 > 2 (T)
breakPoints = 2

breakPoints <= 1 (False)

*/
