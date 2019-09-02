#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b;
ll arr[100009];
int check[100009];
ll func(int x)
{
    ll h, r = n, d = a - b;
    for (int i = n - 1; i >= 0; i--)
    {
        h = arr[i] - x * b;

        if (h > 0)
        {
            r -= (h + d - 1) / d;
            if (r < 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    ll low = 0, high = 1e9, mid;
    while (high - low > 1)
    {
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

    if (func(low))
    {
        cout << low;
    }
    else if (func(high))
    {
        cout << high;
    }
}