#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    int brr[m + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    int x, mid, low = 0, high = n, median;
    while (low <= high)
    {
        mid = (low + high) / 2;
        x = (n + m + 1) / 2 - mid;
        if (mid > 0 && x < n && brr[x - 1] > arr[mid])
        {
            low = mid + 1;
        }
        else if (mid > 0 && x < n && brr[x] < arr[mid - 1])
        {
            high = mid - 1;
        }
        else
        {
            if (mid == 0)
            {
                median = brr[x - 1];
            }
            else if (x == 0)
            {
                median = arr[mid - 1];
            }
            else
            {
                median = max(arr[mid - 1], brr[x - 1]);
            }
        }
    }
    if ((n + m) % 2 == 0)
    {
        if (mid == n)
        {
            median = (median + brr[x]) / 2.0;
        }
        else if (x == m)
        {
            median = (median + arr[mid]) / 2.0;
        }
        else
        {
            median = (median + min(brr[x], arr[mid])) / 2.0;
        }
    }
    cout<<median;
}