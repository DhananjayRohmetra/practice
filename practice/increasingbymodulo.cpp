#include <bits/stdc++.h>
using namespace std;
int arr[400001], n, m;
int func(int x)
{
    int prev = 0, res;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= prev)
        {
            res = m - (arr[i] - prev);
            if (res > x)
            {
                prev = arr[i];
            }
        }
        if (arr[i] < prev)
        {
            res = prev - arr[i];
            if (res > x)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int i;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = m, mid;
    while (high - low > 1)
    {
        //cout << high << " " << low << "\n";
        mid = low + (high - low) / 2;
        if (func(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(func(low))
    cout << low;
    else
    {
        cout<<high;
    }
    
}