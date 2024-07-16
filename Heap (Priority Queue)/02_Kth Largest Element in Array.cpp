// LeetCode : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Way - I (Sorting)
/* Time : O(nlogn) , Space : O(1) */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size() - k; // Find kth Largest element
        return nums[n];
    }
};

// Way - II (Priority Queue [Max Heap])
/* Time : O(nlogn) , Space : O(n) */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int i : nums)
            pq.push(i);
        while (--k)
            pq.pop();
        return pq.top();
    }
};

// Way - III (Priority Queue [Min Heap])
/* Time : O(nlogn) , Space : O(k) */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

// Way - IV (QuickSelect [Hoare's Partition])
/* Time : Worst [O(n * n)] - Average [O(n)] , Space : O(1) */
/* 
1. Choose a pivot element and partition the array such that all elements less than pivot are on left side and all elements greater 
   than pivot are on right side.
2. If pivot index is equal to k-1, then return the element at pivot index.
3. If pivot index is greater than k-1, then search in left subarray.
4. If pivot index is less than k-1, then search in right subarray.
*/
class Solution
{
    int partition(vector<int> &nums, int left, int right)
    {

        int i = left + 1, j = right, pivot = nums[left];
        while (i <= j)
        {
            if (nums[i] < pivot && nums[j] > pivot)
                swap(nums[i++], nums[j--]);
            if (nums[i] >= pivot)
                i++;
            if (nums[j] <= pivot)
                j--;
        }
        // Get the pivot element to its correct position
        swap(nums[left], nums[j]);
        return j;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0, right = n - 1, pivotIdx;

        while (true)
        {
            pivotIdx = partition(nums, left, right);
            if (pivotIdx == k - 1)
                break;
            else if (pivotIdx > k - 1)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
        return nums[pivotIdx];
    }
};