// LeetCode : https://leetcode.com/problems/majority-element-ii/

// Way - I (Brute Force)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // Check for the repeating element
            if (ans.size() == 0 || ans[0] != nums[i])
            {
                int count = 0;
                for (int j = i; j < n; j++)
                {
                    if (nums[i] == nums[j])
                        count++;
                }

                if (count > n / 3)
                    ans.push_back(nums[i]);
                // Maximum majority elements can be only 2
                if (ans.size() == 2)
                    break;
            }
        }
        return ans;
    }
};
// Way - II (Hashing)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i : nums)
            freq[i]++;

        for (auto &it : freq)
        {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }
        return ans;
    }
};

// Way - III (Optimal Hashing)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;

        // Majority Element's value in the array
        int majority = (n / 3) + 1;

        for (int i : nums)
        {
            // Storing Frequency
            freq[i]++;

            // If any element is present n / 3 times
            if (freq[i] == majority)
                ans.push_back(i);

            // As maximum there can be only two majority elements in the array
            if (ans.size() == 2)
                break;
        }
        return ans;
    }
};

// Way - IV (Extended Boyer Moore's Voting Algorithm (Majority Element (n / 2) ) )
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        // Assign any numbers, but should be same
        int element1 = -999, element2 = -999;
        // Two counters for their respective elements
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            if (count1 == 0 && curr != element2)
            {
                count1 = 1;
                element1 = curr;
            }
            else if (count2 == 0 && curr != element1)
            {
                count2 = 1;
                element2 = curr;
            }
            else if (curr == element1)
                count1++;
            else if (curr == element2)
                count2++;
            else
                count1--, count2--;
        }

        // Check if those two elements are majority elements of the array or not
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (element1 == nums[i])
                count1++;
            if (element2 == nums[i])
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(element1);
        if (count2 > n / 3)
            ans.push_back(element2);
        // At the end sort the answer

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* 
Dry Run (Way - IV):
nums[] = {2, 1, 1, 3, 1, 4, 5, 6}

n = 8;
el1 = -999, el2 = -999;
cnt1 = 0, cnt2 = 0;

All checks of first Loop

C1. if (count1 == 0 && curr != element2)
C2. else if (count2 == 0 && curr != element1)
C3. else if (curr == element1)
C4. else if (curr == element2)
C5. else

--> i = 0 (2)
C1 - cnt1 = 1, el1 = 2

--> i = 1 (1)
C1 - cnt2 = 1, el2 = 1

--> i = 2 (1)
C4 - cnt2 = 2

--> i = 3 (3)
C5 - cnt1 = 0, cnt2 = 1

--> i = 4 (1)
C4 - cnt2 = 2

--> i = 5 (4)
C1 - cnt1 = 1, el1 = 4

--> i = 6 (5)
C5 - cnt1 = 0, cnt2 = 1

--> i = 7 (6)
C1 - cnt1 = 1, el1 = 6


cnt1 = 0, cnt2 = 0
Second Iteration
nums[] = {2, 1, 1, 3, 1, 4, 5, 6}
el1 = 6, el2 = 1

--> i = 0 (2)
X
--> i = 1 (1)
cnt2 = 1
--> i = 2 (1)
cnt2 = 2
--> i = 3 (3)
X
--> i = 4 (1)
cnt2 = 3
--> i = 5 (4)
X
--> i = 6 (5)
X
--> i = 7 (6)
cnt1 = 1

cnt1 = 1, cnt2 = 3

cnt1 > n / 3 (False)
cnt2 > n / 3 True
ans = {1}
*/  
