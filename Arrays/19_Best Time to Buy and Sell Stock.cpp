// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Way - I (Brute Force)
int maxProfit(vector<int> &arr) 
{
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] > arr[i]) 
                maxPro = max(arr[j] - arr[i], maxPro);
            
        }
    }
    return maxPro;
}


// Way - II (Optimal)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, Max = INT_MIN, Min = INT_MAX;
        for (int i : prices)
        {
            if (i < Min)
            {
                Min = i;
                Max = 0;
            }
            else if (i > Max)
                Max = i;
            ans = max(ans, Max - Min);
        }
        return ans;
    }
};


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
prices[6] = { 7, 1, 5, 3, 6, 4}
ans = 0, Max = min, Min = max;

--> i = 0 (7) here i = 7
if(i < Min) (T)
Min = 7
Max = 0
ans = 0

--> i = 1 (1)
if(i < Min) T
Min = 1
Max = 0
ans = 0

--> i = 2 (5)
if(i < Min) (F)
else if (T)
Max = 5
ans = (5 - 1) = 4

--> i = 3 (3)
if(i < Min) (F)
else if (F)
ans = 4

--> i = 4 (6)
if(i < Min) (F)
else if (T)
Max = 6
ans = 6 - 1 = 5

--> i = 5 (4)
if(i < Min) (F)
else if (F)
ans = 5

Ans = 5



-------------------
prices[5] = { 7, 6, 4, 3, 1}
In this case, no transactions are done and the max profit = 0.
*/
