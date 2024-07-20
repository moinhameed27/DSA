// GFG : https://bit.ly/3Cf398N

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // If an element is found which is <= x, then store it and move to right
            if (v[mid] <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            // If an element is found which is > x, then move to left
            else
                right = mid - 1;
        }
        return ans;
    }
};