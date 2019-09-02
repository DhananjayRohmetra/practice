#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[300000];
ll n, k;
ll func(ll x)
{
    ll ans = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (arr[i] < x)
        {
            ans = ans + (x - arr[i]);
        }
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    ll d = arr[n / 2];
    ll low = 0;
    ll high = 2000000000;
    while (low + 10 <= high)
    {

        ll mid = (low + high) / 2;
        if (func(mid) > k)
        {
            high = mid - 1;
        }
        else
        {
            d = max(d, mid);
            low = mid + 1;
        }
    }
    for (int i = high; i >= low; i--)
    {
        if (func(i) <= k)
        {
            d = i;
            break;
        }
    }
    cout << d;
}