#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n, i, el;
    cin >> n >> el;
    int arr[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int low = 0, high = n - 1, mid;
    while (high > low)
    {
        // cout << high << " " << low << "\n";
        mid = low + (high - low) / 2;
        if (arr[mid] <= el)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    cout << high;
}