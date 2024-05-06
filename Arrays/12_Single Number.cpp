Coding Ninjas : https://www.codingninjas.com/codestudio/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Way - I (Frequency Count)
int getSingleElement(vector<int> &arr) 
{
  int ans;
  unordered_map<int, int> freq;

  for (int i : arr)
    freq[i]++;

  for (auto j : freq) 
  {
    if (j.second == 1) 
    {
      ans = j.first;
      break;
    }
  }
  return ans;
}


// Way - II (Two Pointers)
int getSingleElement(vector<int> &arr)
{
	int i = 0, j = 1;
    int n = arr.size();
	while(j < n)
	{
		if(arr[i] == arr[j])
		{
			i += 2;
			j += 2;
		}
		else 
			break;
	}	

	return arr[i];
}


// Way - III (XOR)
// Equal Numbers have XOR = 0. So after applying XOR operations on all elements only one single element will remain.
int getSingleElement(vector<int> &arr)
{
	int XOR = 0;
	for(int &i : arr)
		XOR = XOR ^ i;
	return XOR;	
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------------


LeetCode : https://leetcode.com/problems/single-number/
// Way - I (Frequency Count)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans;
        unordered_map <int, int> freq;

        for(int i : nums) 
            freq[i]++;

        for(auto j : freq)
        {
            if (j.second == 1) 
            {
                ans = j.first;
                break;
            }
        }
        return ans;
    }
};


// Way - II (Two Pointers)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        int n = nums.size();

        while(j < n)
        {
            if(nums[i] == nums[j])
            {
                i += 2;
                j += 2;
            }
            else 
                break;
        }

        return nums[i];
    }
};


// Way - III (XOR)
// Equal Numbers have XOR = 0. So after applying XOR operations on all elements only one single element will remain.
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int XOR = 0;
        for(int &i : nums)
            XOR ^= i;
        return XOR;
    }
};
