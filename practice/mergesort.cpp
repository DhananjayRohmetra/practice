#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    int temp1[len1 + 1];
    int temp2[len2 + 1];
    for (int i = 0; i < len1; i++)
    {
        temp1[i] = arr[l + i];
    }
    for (int i = 0; i < len2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2)
    {
        if (temp1[i] >= temp2[j])
        {
            arr[k] = temp2[j];
            j++;
            k++;
        }
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            i++;
            k++;
        }
    }
    while (i < len1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < len2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, i;
    cin >> n;
    int arr[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}