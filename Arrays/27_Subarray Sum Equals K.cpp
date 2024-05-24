// LeetCode : https://leetcode.com/problems/subarray-sum-equals-k/

// Way - I (Brute Force)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                // Sum of Subarray [i...j]
                for (int K = i; K <= j; K++)
                    sum += nums[K];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};

// Way - II (Better)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};

// Way - III (Hashing)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        // As checking on the basis of difference (sum - k), if result comes 0, then it means there is a subarray
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};