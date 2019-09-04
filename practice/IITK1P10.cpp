#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> vec;
ll n, q, tim = 0;
ll in[100009], out[100009], val[100009], tree[900009], arr[200009];

void dfs(ll s, ll par)
{
    tim++;
    in[s] = tim;

    for (int i = 0; i < vec[s].size(); i++)
    {
        if (vec[s][i] != par)
        {
            dfs(vec[s][i], s);
        }
    }
    tim++;
    out[s] = tim;
}
void build(ll node, ll start, ll end)
{

    if (start == end)
    {
        if (arr[start] == 0)
        {
            tree[node]++;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}
void update(int node, int start, int end, int idx, int v)
{
    if (start == end)
    {

        if (arr[idx] == 0 && v != 0)
        {
            tree[node]--;
        }
        if (arr[idx] != 0 && v + arr[idx] == 0)
        {
            tree[node]++;
        }
        arr[idx] += v;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
        {
            update(2 * node + 1, start, mid, idx, v);
        }
        else
        {
            update(2 * node + 2, mid + 1, end, idx, v);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2 * node + 1, start, mid, l, r);
    int p2 = query(2 * node + 2, mid + 1, end, l, r);
    return p1 + p2;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    ll x, y, v;
    cin >> n >> q;
    vec.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1, -1);
    int order[tim + 1];
    for (int i = 1; i <= n; i++)
    {
        order[in[i]] = i;
        order[out[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i <= 2 * n; i++)
    {
        arr[i] = val[order[i]];
    }

    char f;
    build(1, 1, 2 * n);

    while (q--)
    {
        cin >> f;
        if (f == 'Q')
        {
            cin >> x;
            cout << query(1, 1, 2 * n, in[x], out[x]) / 2 << "\n";
        }
        if (f == 'U')
        {
            cin >> x >> v;
            update(1, 1, 2 * n, in[x], v);
            update(1, 1, 2 * n, out[x], -v);
        }
    }
}