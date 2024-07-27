// LeetCode : https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int> pq;
        int n = heights.size(), i;
        for (i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            // If going from upper to lower building, nothing will be used
            if (diff <= 0)
                continue;
            // Use bricks and push the difference into queue
            bricks -= diff;
            pq.push(diff);
            // Whenever bricks become negative, use ladders and if no ladders are left, break
            if (bricks < 0)
            {
                if (ladders > 0)
                {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                else
                    break;
            }
        }
        return i;
    }
};