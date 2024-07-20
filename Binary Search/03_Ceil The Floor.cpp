// GFG : https://bit.ly/3CgDDjE

class Solution
{
public:
    vector<int> getFloorAndCeil(int x, vector<int> arr)
    {
        int Floor = INT_MIN, Ceil = INT_MAX;
        vector<int> ans(2, -1);
        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            if (curr > Floor && curr <= x)
                Floor = curr, ans[0] = curr;
            if (curr < Ceil && curr >= x)
                Ceil = curr, ans[1] = curr;
        }
        return ans;
    }
};