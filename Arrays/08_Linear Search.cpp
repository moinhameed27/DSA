Coding Ninjas : https://www.codingninjas.com/codestudio/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == num)
            return i;
    }
    return -1;
}
