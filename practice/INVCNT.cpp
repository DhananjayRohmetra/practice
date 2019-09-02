#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int l, int mid, int r)
{
    int inv_cnt = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int temp1[n1 + 1];
    int temp2[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            inv_cnt += (mid - i);
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
    return inv_cnt;
}
int merge_sort(int arr[], int l, int r)
{
    int inv_cnt = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv_cnt = merge_sort(arr, l, mid);
        inv_cnt += merge_sort(arr, mid + 1, r);
        inv_cnt += merge(arr, l, mid, r);
    }
    return inv_cnt;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << merge_sort(arr, 0, n - 1);

   
}