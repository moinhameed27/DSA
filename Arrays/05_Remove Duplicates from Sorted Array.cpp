Coding Ninjas : https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int removeDuplicates(vector<int> &arr, int n)
{
    int duplicates = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            duplicates++;
    }
    return n - duplicates;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

LeetCode : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Way - I (Using Extra Space)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int duplicates = 0;
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                if (nums[i] == nums[i + 1])
                    duplicates++;
                else
                    temp.push_back(nums[i]);
            }
            else if (i == n - 1)
                temp.push_back(nums[i]);
        }
        nums = temp;
        return n - duplicates;
    }
};

// Way - II (In-Place Removal of Duplicated - Two Pointers)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0, j = 1;
        while(j < n)
        {
            if(nums[i] != nums[j])
                i++;
            
            nums[i] = nums[j];
            j++;
        }
        return i + 1;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Dry Run(Way - II):

nums[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}

n = 5;
i = 0, j = 1

--> 1
if(0 != 0) (F)
j = 2

--> 2
if(0 != 1) (T)
i = 1
nums[1] = nums[2] --> {0, 1}
j = 3

--> 3
if(1 != 1) (F)
j = 4

--> 4
if(1 != 1) (F)
j = 5

--> 5
if(1 != 2) (T)
i = 2
nums[2] = nums[5] --> {0, 1, 2}
j = 6

--> 6
if(2 != 2) (F)
j = 7

--> 7
if(2 != 3) (T)
i = 3
nums[3] = nums[7] --> {0, 1, 2, 3}
j = 8

--> 8
if(3 != 3) (F)
j = 9

--> 9
if(3 != 4) (T)
i = 4
nums[4] = nums[9] --> {0, 1, 2, 3, 4}
j = 10


Number of Unique elements = i + 1 --> 4 + 1 = 5
Unique Array : {0, 1, 2, 3, 4}
*/