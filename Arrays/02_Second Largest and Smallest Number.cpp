Coding Ninjas : https://www.codingninjas.com/codestudio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Way - I (Sort and Get the Second and Second Last Element)
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    sort(a.begin(), a.end());
    return {a[n - 2], a[1]};
}

// Way - II (WIthout Sorting)
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // If current element is greater than max, assign max to second Max and max to current element
        if (a[i] > max)
        {
            secondMax = max;
            max = a[i];
        }
        // If current element is not max and second Max is less than current element, update second Max
        else if (a[i] != max && secondMax < a[i])
            secondMax = a[i];
        // If current element is less than min, assign min to second min and min to current element
        if (a[i] < min)
        {
            secondMin = min;
            min = a[i];
        }
        // If current element is not min and second Min is greater than current element, update second Min
        else if (a[i] != min && secondMin > a[i])
            secondMin = a[i];
    }
    return {secondMax, secondMin};
}
