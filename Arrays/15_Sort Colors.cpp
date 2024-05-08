// LeetCode : https://leetcode.com/problems/sort-colors/

// Two Pointers
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int a = 0, b = 0;
        int c = n - 1;
        while (b <= c)
        {
            if (nums[b] == 0)
            {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if (nums[b] == 1)
                b++;
            else
            {
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
nums[6] = {2, 0, 2, 1, 1, 0}
a = 0, b = 0, c = 5

--> b = 0
else
swap(b, c)
nums = {0, 0, 2, 1, 1, 2}
c = 4

--> b = 0
if
swap(a, b)
nums = {0, 0, 2, 1, 1, 2}
a = 1, b = 1

--> b = 1
if
swap(a, b)
nums = {0, 0, 2, 1, 1, 2}
a = 2, b = 2

--> b = 2
else
swap(b, c)
nums = {0, 0, 1, 1, 2, 2}
c = 3

--> b = 3
else if 
b = 4

nums = {0, 0, 1, 1, 2, 2}


---------------------------
Corner Case (Why b <= c is needed instead of b < c && why b is not incremented in else case)
nums[3] = {2, 0, 1}
a = 0, b = 0, c = 2

--> b = 0
else
swap(b, c)
nums = {1, 0, 2}
c = 1

--> b = 0
else if
b = 1

--> b = 1
if
swap(a, b)
nums = {0, 1, 2}
a = 1
b = 2


nums = {0, 1, 2}


*/