// LeetCode : https://leetcode.com/problems/next-permutation/

// Way - I (Brute Force)
/*
1. Get all permutations in the sorted order (Recursion)
2. Select the next larger than current permutation
3. If already the biggest permutation, then choose first
*/

// Way - II (STL)
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};

// Way - III (Optimal - Self written)
/*
1. Find the first Breakpoint iterating backwards - when nums[i] < nums[i + 1]
2. If there is no breakpoint then simply reverse the array and return. (Corner Case)
3. Find the smallest number after that breakpoint index but greater than the breakpoint number and swap them.
4. Reverse the array after the breakpoint index.
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int idx = -1;
        int n = nums.size();

        // Finding first breakpoint iterating backwards
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i;
                break;
            }
        }

        // Corner Case - No Breakpoint
        if (idx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Swap the index element with the  smallest element after index but bigger than itself
        for (int i = n - 1; i > idx; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Reverse all elements after index
        reverse(nums.begin() + idx + 1, nums.end());
    }
};


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
nums[] = {2, 1, 5, 4, 3, 0, 0}
1. Breakpoint iterating backwards
index = 1, element = 1
2. Swap with smallest element after it but bigger than it
element = 3
nums[] = {2, 3, 5, 4, 1, 0, 0}
3. Reverse all elements after idx
nums[] = {2, 3, 0, 0, 1, 4, 5}


-------------------------------
Corner Case:
nums[] = {5, 4, 3, 2, 1}
In this case, it is the last permutation so to get the first permutation, reverse complete array
*/