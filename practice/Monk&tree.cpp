#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> v;
ll ha[10000000], a[100009], k;
ll ans = 0;
void dfs(ll s, ll xorr)
{
    xorr = xorr ^ a[s];
    ans += ha[xorr ^ k];
    ha[xorr]++;
    for (auto it = v[s].begin(); it != v[s].end(); it++)
    {
        dfs(*it, xorr);
    }
    ha[xorr]--;
}

int main()
{
    ll n;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    v.resize(n + 1);
    ha[0] = 1;
    ll x;
    for (ll i = 1; i <= n - 1; i++)
    {
        cin >> x;
        v[x].push_back(i + 1);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}