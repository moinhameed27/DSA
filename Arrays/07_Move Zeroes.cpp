Coding Ninjas : https://www.codingninjas.com/codestudio/problems/ninja-and-the-zero-s_6581958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<int> moveZeros(int n, vector<int> a)
{
    int i = 0, j = 0;
    while (i < n)
    {
        if (a[i] != 0)
        {
            a[j] = a[i];
            j++;
        }
        i++;
    }

    while (j < n)
    {
        a[j] = 0;
        j++;
    }

    return a;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

LeetCode : https://leetcode.com/problems/move-zeroes/

class Solution {
public:
void moveZeroes(vector<int>& nums) 
{
    int n = nums.size();
    int i = 0, j = 0;
    while(i < n)
    {
        if(nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
            i++;
    }

    while(j < n)
    {
        nums[j] = 0;
        j++;
    }
        
    }
};


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

Dry Run:
nums[5] = {0, 1, 0, 3, 12}

n = 5
i = 0, j = 0

--> i = 0
if(0 != 0) (F)

--> i = 1
if(0 != 1) (T)
nums[0] = nums[1] 
nums[5] = {1, 1, 0, 3, 12}
j = 1

--> i = 2
if(0 != 0) (F)

--> i = 3
if(0 != 3) (T)
nums[1] = nums[3]
nums[5] = {1, 3, 0, 3, 12}
j = 2

--> i = 4
if(0 != 12) (T)
nums[2] = nums[4]
nums[5] = {1, 2, 12, 3, 12}
j = 3

---------------------------
--> j = 3
nums[3] = 0
nums[5] = {1, 2, 12, 0, 12}

--> j = 4
nums[4] = 0
nums[5] = {1, 2, 12, 0, 0}

*/