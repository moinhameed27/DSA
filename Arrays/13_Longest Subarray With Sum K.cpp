// Coding Ninjas : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM

// Sliding Window
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    long long sum = 0;
    int length = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        sum += a[j];

        while (sum > k)
        {
            sum -= a[i];
            i++;
        }

        if (sum == k)
            length = max(length, j - i + 1);
        j++;
    }

    return length;
}