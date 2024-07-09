// LeetCode : https://leetcode.com/problems/next-greater-element-i/description/

// Way - I (Brute Force)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n1; i++)
        {
            bool isPresent = false;
            for (int j = 0; j < n2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    for (int k = j + 1; k < n2; k++)
                    {
                        if (nums2[k] > nums1[i])
                        {
                            ans.push_back(nums2[k]);
                            isPresent = true;
                            break;
                        }
                    }
                    if (!isPresent)
                        ans.push_back(-1);
                    break;
                }
            }
        }
        return ans;
    }
};

// Way - II (Hashing + Stack)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for (int num = n2 - 1; num >= 0; num--)
        {
            // Keep Checking until there's greater element found
            while (!st.empty() && st.top() < nums2[num])
                st.pop();
            // If stack is empty, it means there's no element greater to the current one
            if (st.empty())
                mp[nums2[num]] = -1;
            // Otherwise store the top element of stack for current element
            else
                mp[nums2[num]] = st.top();
            // Push current element into stack
            st.push(nums2[num]);
        }

        vector<int> ans;
        // Get answers as stored in map
        for (int num : nums1)
            ans.push_back(mp[num]);

        return ans;
    }
};