// LeetCode : https://leetcode.com/problems/time-needed-to-buy-tickets/description/

// Way - I (Brute Force)
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0, n = tickets.size();
        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                // Increment time only if a person has a pending ticket
                if (tickets[i] > 0)
                    tickets[i]--, time++;
                // If kth index person has bought all his tickets, return
                if (i == k && tickets[k] == 0)
                    return time;
            }
        }
        return 0;
    }
};

// Way - II (Better [Queue])
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        queue<pair<int, int>> q;
        // Pushing all elements along with their index
        for (int i = 0; i < tickets.size(); i++)
            q.push({tickets[i], i});

        while (!q.empty())
        {
            auto [value, idx] = q.front();
            q.pop();
            value--;
            time++;
            // If kth person has bought all his tickets, return
            if (idx == k && value == 0)
                break;
            // If the current person still has any tickets to buy, send him back to queue
            if (value > 0)
                q.push({value, idx});
        }
        return time;
    }
};

// Way - III (Optimal)
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0, n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            // If the person is before kth person, he can buy either all his tickets if his tickets are less than kth person
            // Otherwise, he can buy only kth person's tickets
            if (i <= k)
                time += min(tickets[i], tickets[k]);
            // If the person is after kth person, he can buy either all his tickets if his tickets are less than kth person
            // Otherwise, he can buy only kth person's tickets - 1. Because kth person will buy his tickets and leave.
            else
                time += min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
};