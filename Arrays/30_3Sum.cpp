// LeetCode : https://leetcode.com/problems/3sum/

// Way - I (Brute Force)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        // Set to store only unique triplets
        set<vector<int>> st;

        // Check all possible triplets
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        // Sorting to check for Duplicate Triplets
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        // store the set elements in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


// Way - II (Hashing) - TLE (311 / 313)
// nums[k] = - (nums[i] + nums[j])
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        // Set for storing Unique triplets
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            // Another set for finding the third element
            set<int> hashSet;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};


// Way - III (Two Pointers
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) 
        {
            // To skip multiple same elements at the i pointer (if any)
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // Two Pointers : One after i and one at the end of nums
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                // Equal Case
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // To skip multiple same elements at the j pointer (if any)
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    // To skip multiple same elements at the k pointer (if any)
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Example:
nums[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2}

Two Pointers Explanation:
--> Sort the array
--> i pointer will traverse the whole array but skip the repeated elements
--> for every i there will be two pointers, check for possible triplets. If sum of all is less than 0 then
increase the j pointer and if sum is greater then decrese the k pointer.
--> If found equal to 0, add values to answer but before traversing again, skip the repeated 
elements at the j and k pointer.
*/