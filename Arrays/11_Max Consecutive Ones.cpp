/*
LeetCode
Problem : Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, ans = 0;
        for (int i : nums)
        {
            if (i == 1)
                count++;
            ans = max(ans, count);
            if (i == 0)
                count = 0;
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
LeetCode
Problem : Max Consecutive Ones III (After flipping k Zeros into Ones)
Link: https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0, countZeros = 0;
        
        while(j < n)
        {
            if(nums[j] == 0)
                countZeros++;

            while(countZeros > k)
            {
                if(nums[i] == 0)
                    countZeros--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Coding Ninjas
Problem : Traffic
Link: https://www.codingninjas.com/codestudio/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

int traffic(int n, int m, vector<int> vehicle) 
{
	int i = 0, j = 0;
	int count = 0, flips = 0;
	while(j < n)
	{
		if(vehicle[j] == 0)
		{
			flips++;
		}

		while(flips > m)
		{
			if(vehicle[i] == 0)
				flips--;
			i++;
		}

		count = max(count, j - i + 1);
		j++;
	}
	return count;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
nums[6] = {0, 1, 0, 0, 1, 0}
k = 3, n = 6
i = 0, j = 0
count = 0, flips = 0


--> j = 0
if(0 == 0) (T)
    flips = 1
while(1 > 3) (F)

count = 1

--> j = 1
if(1 == 0) (T)
    flips = 1
while(1 > 3) (F)

count = 2

--> j = 2
if(0 == 0) (T)
    flips = 2
while(2 > 3) (F)

count = 3

--> j = 3
if(0 == 0) (T)
    flips = 3
while(3 > 3) (F)

count = 4

--> j = 4
if(1 == 0) (F)
    flips = 3

while(3 > 3) (F)

count = 5

--> j = 5
if(0 == 0) (T)
    flips = 4

while(4 > 3) (T)
if(1 == 0) (F)
    i = 1
if(0 == 0) (T)
    flips = 3
    i = 2

count = max(5, 4) = 5
*/