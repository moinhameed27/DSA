// LeetCode : https://leetcode.com/problems/majority-element/


// Way - I (Brute Force)
int majorityElement(vector<int> nums)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > (n / 2))
            return nums[i];
    }

    return -1;
}


// Way - II (Hashing - Frequency Count)
int majorityElement(vector<int> nums)
{
    int n = nums.size();

    map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[nums[i]]++;

    for (auto it : freq)
    {
        if (it.second > (n / 2))
            return it.first;
    }

    return -1;
}


// Way - III (Boyer-Moore Voting Algorithm)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, element;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                element = nums[i];
            count += (nums[i] == element) ? 1 : -1;
        }
        return element;
    }
};



-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run (Boyer-Moore Voting Algorithm):
nums[7] = { 2, 2, 1, 1, 1, 2, 2}
n = 7, count = 0, element

--> i = 0
if(count == 0) (T)
element = 2
count = 1 (+1)

--> i = 1
if(count == 0) (F)
count = 2 (+1)

--> i = 2
if(count == 0) (F)
count = 1 (-1)

--> i = 3
if(count == 0) (F)
count = 0 (-1)

--> i = 4
if(count == 0) (T)
element = -1
count = 1 (+1)

--> i = 5
if(count == 0) (F)
count = 0 (-1)

--> i = 6
if(count == 0) (T)
element = 2
count = 1 (+1)

*/