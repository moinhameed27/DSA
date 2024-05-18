// GFG : https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// Way - I (Brute Force)
class Solution
{
    bool linearSearch(vector<int> &a, int num)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] == num)
                return true;
        }
        return false;
    }
    int longestSuccessiveElements(vector<int> &a)
    {
        int n = a.size();
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            int num = a[i];
            int count = 1;

            // Finding every next element of current element
            while (linearSearch(a, num + 1) == true)
            {
                num++;
                count++;
            }

            longest = max(longest, count);
        }
        return longest;
    }
};

// Way - II (Sorting)
class Solution
{
    int longestSuccessiveElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        int longest = 1, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            // If sequence is consecutive
            if (nums[i] - prev == 1)
                count++;
            // Sequence is not Consecutive
            else if (nums[i] != prev)
                count = 1;

            prev = nums[i];
            longest = max(longest, count);
        }
        return longest;
    }
};

// Way - III (Set)
class Solution
{
    int longestSuccessiveElements(vector<int> &nums)
    {
        int longest = 1;
        unordered_set<int> st;

        for (int i : nums)
            st.insert(nums[i]);

        for (auto it : st)
        {
            // Checking if the current element is the smallest of it's sequence, as first element won't have any previous consecutive number
            if (st.find(it - 1) == st.end())
            {
                int num = it;
                int count = 1;
                // Counting how many elements are there in the sequence
                while (st.find(num + 1) != st.end())
                {
                    count++;
                    num++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
