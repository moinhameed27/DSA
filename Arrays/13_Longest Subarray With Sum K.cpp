/*
Coding Ninjas
Problem : Problem : Longest Subarray With Sum K (Positives)
Link : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM
*/

// Way - I (Brute Force)
int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size();

    int length = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];

            if (sum == k)
                length = max(length, j - i + 1);
        }
    }
    return length;
}

// Way - II (Hashing) - Partially Submission due to long constraints - Better
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int length = 0, n = a.size();
    long long sum = 0;
    unordered_map<long long, int> prefixMap;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
            length = i + 1;

        long long rem = sum - k;
        if (prefixMap.find(rem) != prefixMap.end())
        {
            int len = i - prefixMap[rem];
            length = max(length, len);
        }

        // Corner - Case (Array including Zeros)
        if (prefixMap.find(sum) == prefixMap.end())
            prefixMap[sum] = i;
    }
    return length;
}

// Way - III (Sliding Window) - Optimal
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    long long sum = 0;
    int length = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        sum += a[j];

        while (sum > k)
        {
            sum -= a[i];
            i++;
        }

        if (sum == k)
            length = max(length, j - i + 1);
        j++;
    }

    return length;
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
Coding Ninjas
Problem : Longest Subarray With Sum K (Positives + Negatives)
Link : https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

// Hashing - Optimal
#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
    int length = 0, n = nums.size();
    long long sum = 0;
    unordered_map<long long, int> prefixMap;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
            length = i + 1;

        long long rem = sum - k;
        if (prefixMap.find(rem) != prefixMap.end())
        {
            int len = i - prefixMap[rem];
            length = max(length, len);
        }

        // Corner - Case (Array including Zeros)
        if (prefixMap.find(sum) == prefixMap.end())
            prefixMap[sum] = i;
    }
    return length;
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
arr[10] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3}
n = 10, k = 3
sum = 0, length = 0

--> i = 0
sum = 1
if(sum == k) (F)

rem = -2
if(find(rem)) (F)

if(!find(sum)) (T)
prefixMap[1] = 0
prefixMap {1} = {0}

--> i = 1
sum = 3
if(sum == k) (T)
length = 2

rem = 0
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[3] = 1
prefixMap {1, 3} = {0, 1}

--> i = 2
sum = 6
if(sum == k) (F)

rem = 3
if(find(rem)) (T)
{
    len = 2 - 1 = 1
    length = 2
}

if(!find(sum)) (F)
prefixMap[6] = 2
prefixMap {1, 3, 6} = {0, 1, 2}


--> i = 3
sum = 7
if(sum == k) (F)

rem = 4
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[7] = 3
prefixMap {1, 3, 6, 7} = {0, 1, 2, 3}


--> i = 4
sum = 8
if(sum == k) (F)

rem = 5
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[8] = 4
prefixMap {1, 3, 6, 7, 8} = {0, 1, 2, 3, 4}

--> i = 5
sum = 9
if(sum == k) (F)

rem = 6
if(find(rem)) (T)
{
    len = 5 - 2 = 3
    length = 3
}

if(!find(sum)) (F)
prefixMap[9] = 5
prefixMap {1, 3, 6, 7, 8, 9} = {0, 1, 2, 3, 4, 5}


--> i = 6
sum = 10
if(sum == k) (F)

rem = 7
if(find(rem)) (T)
{
    len = 6 - 3 = 3
    length = 3
}

if(!find(sum)) (F)
prefixMap[10] = 5
prefixMap {1, 3, 6, 7, 8, 9, 10} = {0, 1, 2, 3, 4, 5, 6}


--> i = 7
sum = 14
if(sum == k) (F)

rem = 11
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[14] = 7
prefixMap {1, 3, 6, 7, 8, 9, 10, 14} = {0, 1, 2, 3, 4, 5, 6, 7}


--> i = 8
sum = 16
if(sum == k) (F)

rem = 13
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[16] = 8
prefixMap {1, 3, 6, 7, 8, 9, 10, 14, 16} = {0, 1, 2, 3, 4, 5, 6, 7, 8}


--> i = 9
sum = 19
if(sum == k) (F)

rem = 16
if(find(rem)) (F)

if(!find(sum)) (F)
prefixMap[19] = 9
prefixMap {1, 3, 6, 7, 8, 9, 10, 14, 16, 19} = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}




Corner - Case (Including 0s)
arr[4] = {2, 0, 0 ,3}
if the last check is not written in code then, it will fail
*/



