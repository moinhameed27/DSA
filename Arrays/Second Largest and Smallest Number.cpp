vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            secondMax = max;
            max = a[i];
        }
        else if (a[i] != max && secondMax < a[i])
            secondMax = a[i];
        if (a[i] < min)
        {
            secondMin = min;
            min = a[i];
        }
        else if (a[i] != min && secondMin > a[i])
            secondMin = a[i];
    }
    return {secondMax, secondMin};
}
