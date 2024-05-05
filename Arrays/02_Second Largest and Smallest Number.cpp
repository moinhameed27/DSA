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

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:

a[5] = {1, 2, 3, 4, 5}

--> i = 0;
IF :    secondMax = max = INT_MIN
        max = a[0] = 1

IF :    secondMin = min = INT_MAX
        min = a[0] = 1;

--> i = 1;
IF :    secondMax = max = 1
        max = a[1] = 2

ELIF :  secondMin = a[1] = 1;

--> i = 2;
IF :    secondMax = max = 2
        max = a[2] = 3

--> i = 3;
IF :    secondMax = max = 3
        max = a[2] = 4

--> i = 4;
IF :    secondMax = max = 4
        max = a[2] = 5


Second max = 4;
Second min = 2;

*/