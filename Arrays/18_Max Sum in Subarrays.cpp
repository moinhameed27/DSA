// GFG : https://bit.ly/3SLFFhs


// Way - I
class Solution
{
public:
    long long pairWithMaxSum(long long arr[], long long N)
    {
        long long ans = 0;
        long long i = 0;
        while (i < N - 1)
        {
            long long sum = arr[i] + arr[i + 1];
            ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};


