#include <bits/stdc++.h>
using namespace std;
#define ll long long
void union1(ll x, ll y);
ll findset(ll x);
ll issameset(ll x, ll y);
ll parent[100002];
ll size1[100002];

multiset<ll> s1;
int main()
{
    ll n, q, x, y, x1, y1;

    multiset<ll>::iterator it;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        size1[i] = 1;
        parent[i] = i;
        s1.insert(1);
    }
    while (q--)
    {
        cin >> x >> y;
        x1 = findset(x);
        y1 = findset(y);
        if (issameset(x1, y1) == 0)
        {
            s1.erase(s1.find(size1[x1]));
            s1.erase(s1.find(size1[y1]));
            size1[x1] += size1[y1];
            size1[y1] = 0;
            s1.insert(size1[x1]);

            union1(x, y);
        }
        it = s1.end();
        it--;
        cout << *it - *s1.begin() << endl;
    }
}
void union1(ll x, ll y)
{
    parent[findset(y)] = findset(x);
}
ll findset(ll x)
{
    if (parent[x] == x)
        return x;
    else
        parent[x] = findset(parent[x]);
    return parent[x];
}
ll issameset(ll x, ll y)
{
    if (findset(x) == findset(y))
        return 1;
    else
        return 0;
}