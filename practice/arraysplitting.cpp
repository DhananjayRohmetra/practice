#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0;
    vector<int> vec;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        if (i != 0)
        {
            vec.push_back(sum);
        }
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    ll ans = sum;
    for (int i = 0; i < k - 1; i++)
    {
        ans += vec[i];
    }
    cout << ans;
}