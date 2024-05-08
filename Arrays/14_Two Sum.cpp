/*
Coding Ninjas
Problem : Two Sum
Link: https://www.naukri.com/code360/problems/reading_6845742
*/

// Way - I (Brute Force)
string twoSum(int n, vector<int> &arr, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] + arr[j] == target) 
                return "YES";
        }
    }
    return "NO";
}


// Way - II (Two Pointers + Sorting)
string read(int n, vector<int> book, int target) 
{
    sort(begin(book), end(book));
    int i = 0, j = n - 1;

    while (i < j) 
    {
        int sum = book[i] + book[j];

        if (sum == target)
            return "YES";

        else if (sum < target)
            i++;

        else
            j--;
    }
    return "NO";
}


// Way - III (Hashing)
string read(int n, vector<int> book, int target)
{
    unordered_map <int, int> hash;
    for(int i = 0; i < n; i++)
    {
        int rem = target - book[i];

        if(hash.find(rem) != hash.end())
            return "YES";
        
        hash[book[i]] = i;
    }
    return "NO";
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
LeetCode
Problem : Two Sum
Link : https://leetcode.com/problems/two-sum/
*/


// Way - I (Brute Force)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};


// Way - II (Hashing)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];

            if (hash.find(rem) != hash.end())
                return {hash[rem], i};

            hash[nums[i]] = i;
        }
        return {};
    }
};



-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run - Hashing:
nums[5] = {2, 3, 1, 5, 6}, target = 9
int n = 5

--> i = 0
rem = 7
if(find(rem)) (F)

hash{2} = 0
hash {2} = {0}

--> i = 1
rem = 6
if(find(rem)) (F)

hash{3} = 1
hash {2, 3} = {0, 1}

--> i = 2
rem = 8
if(find(rem)) (F)

hash{1} = 2
hash {2, 3, 1} = {0, 1, 2}

--> i = 3
rem = 4
if(find(rem)) (F)

hash{4} = 3
hash {2, 3, 1, 4} = {0, 1, 2, 3}

--> i = 4
rem = 3
if(find(rem)) (T)
return {1, 4};

*/




