// GFG :

// Way - I (Sorting)
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        sort(arr, arr + r + 1);
        return arr[k - 1];
    }
};

// Way - II (Min Heap)
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= r; i++)
            pq.push(arr[i]);
        while (--k)
            pq.pop();
        return pq.top();
    }
};

// Way - III (Max Heap)
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i <= r; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

// Way - IV (Quick Select [Haore's Partition]) (Using Kth Largest Method)
class Solution
{
public:
    int partition(int arr[], int left, int right)
    {
        int pivot = arr[left];
        int i = left + 1, j = right;
        while (i <= j)
        {
            if (arr[i] < pivot && arr[j] > pivot)
                swap(arr[i++], arr[j--]);
            if (arr[i] >= pivot)
                i++;
            if (arr[j] <= pivot)
                j--;
        }
        swap(arr[left], arr[j]);
        return j;
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        int left = 0, right = r, pivotIdx;
        // We need to find Kth smallest, so converting it to Kth Largest
        k = (r + 1) - k + 1;
        while (true)
        {
            pivotIdx = partition(arr, left, right);
            if (pivotIdx == k - 1)
                break;
            else if (pivotIdx > k - 1)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
        return arr[pivotIdx];
    }
};