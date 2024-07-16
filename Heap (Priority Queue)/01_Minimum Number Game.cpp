// LeetCode : https://leetcode.com/problems/minimum-number-game/description/

// Way - I (Sorting)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        // Sort the elements and swap the adjacent elements
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};

// Way - II (Priority Queue)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        // Push all numbers to Queue
        for (int i : nums)
            pq.push(i);
        // Pop two elements and push them in reverse order
        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            ans.push_back(pq.top());
            ans.push_back(top);
            pq.pop();
        }
        return ans;
    }
};