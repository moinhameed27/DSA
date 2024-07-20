// GFG : https://bit.ly/3SVcOqW

/* Find the first and last index of target number, then count the subarray size */
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int binarySearch(int arr[], int left, int right, int x, bool firstIndex)
    {
        int ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x)
                left = mid + 1;
            else if (arr[mid] > x)
                right = mid - 1;
            else
            {
                ans = mid;
                if (firstIndex)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return ans;
    }
    int count(int arr[], int n, int x)
    {
        int firstIndex = binarySearch(arr, 0, n - 1, x, true);
        // If element is not present in the array, return from here, otherwise find last index
        if (firstIndex == -1)
            return 0;
        int lastIndex = binarySearch(arr, 0, n - 1, x, false);
        return lastIndex - firstIndex + 1;
    }
};