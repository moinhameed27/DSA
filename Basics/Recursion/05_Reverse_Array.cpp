// Way - I (Brute Force)
void reverseArray(int arr[], int n)
{
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
        ans[n - i - 1] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

// Way - II (Two Pointers)
void reverseArray(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// Way - III (Recursion)
void reverseArray(int arr[], int start, int end)
{
    if (start == end)
        return;
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}
