// GFG :

/* Find the minimum element in the rotated sorted array, it's index will be showing the number of rotations */
// Way - I
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int left = 0, mid, right = arr.size() - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] < arr[right])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

// Way - II
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int left = 0, mid, right = arr.size() - 1;
        int minIdx = -1, minEl = INT_MAX;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] <= arr[right])
            {
                if (arr[mid] < minEl)
                    minEl = arr[mid], minIdx = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return minIdx;
    }
};