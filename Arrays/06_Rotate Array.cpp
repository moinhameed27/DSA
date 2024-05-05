/*
Coding Ninjas
Left Rotate an Array by One
https://www.codingninjas.com/codestudio/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <bits/stdc++.h>

void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

vector<int> rotateArray(vector<int> &arr, int n)
{   
    // Reverse Complete Array
    reverse(arr, 0, n - 1);
    // Reverse All elements except Last
    reverse(arr, 0, n - 1 - 1);
    return arr;
}

/*
Coding Ninjas
Left Rotate by D Places
https://www.codingninjas.com/codestudio/problems/rotate-array_1230543?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();
    k %= n;
    // Reverse complete Array
    reverse(arr, 0, n - 1);
    // Reverse first n - k elements
    reverse(arr, 0, n - k - 1);
    // Reverse last k elements
    reverse(arr, n - k, n - 1);
    return arr;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
Rotate Array by k PLaces
https://leetcode.com/problems/rotate-array/
*/

class Solution
{
    void reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        // Reverse Complete Array
        reverse(nums, 0, n - 1);
        // Reverse first k elements
        reverse(nums, 0, k - 1);
        // Reverse elements after k
        reverse(nums, k, n - 1);
    }
};