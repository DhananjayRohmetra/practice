// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<vector<int>> adj;
// int spath(int u, int v)
// {
//     queue<int> q;
//     int visited[n + 2], dis[n + 2];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = 0;
//         dis[i] = 0;
//     }
//     q.push(u);
//     dis[u] = 0;
//     visited[u] = 1;
//     while (!q.empty())
//     {
//         int s = q.front();
//         for (int i = 0; i < adj[s].size(); i++)
//         {
//             if (visited[adj[s][i]] == 0)
//             {
//                 visited[adj[s][i]] = 1;
//                 dis[adj[s][i]] = dis[s] + 1;
//                 q.push(adj[s][i]);
//             }
//         }
//     }

//     if (visited[v] == 1)
//     {
//         return dis[v];
//     }
//     else
//     {
//         return 1000000000;
//     }
// }
// int main()
// {
//     freopen("input.txt", "r", stdin);
//     cin >> n;
//     int arr[n + 1];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int bits[61];
//     memset(bits, 0, sizeof(bits));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] & (1 << j))
//             {
//                 bits[j]++;
//             }
//         }
//     }
//     for (int i = 0; i < 60; i++)
//     {
//         if (bits[i] > 2)
//         {
//             cout << "3";
//             return 0;
//         }
//     }
//     vector<vector<int>> adj;
//     adj.resize(n);
//     vector<pair<int, int>> edges;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] & arr[j])
//             {
//                 edges.push_back({i, j});
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
//     }
//     int ans = 1000000000;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         vector<int>::iterator it = std::find(adj[u].begin(), adj[u].end(), v);
//         adj[u].erase(it);
//         it = std::find(adj[v].begin(), adj[v].end(), u);
//         adj[v].erase(it);

//         ans = min(ans, spath(u, v) + 1);
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     cout << ans;
// }

#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
 
 
//#include <ext/pb_ds/assoc_container.hpp>
 
 
#define fi first
#define se second
#define th third
 
#define en "\n"
#define sqrt(n) sqrt((long double) n)
#define all(c) (c).begin() , (c).end()
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define elif else if
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define sz(a) ((long long)((a).size()))
#define int long long
 
using namespace std;
 
template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };
 
int gcd(int a,int b){
    while (a && b)
        if (a>b) a=a%b; else b=b%a;
    return a+b;
}
 
int bp(int a,int b,int &md){
    int res=1;
    while (b) {
        if (b&1) res*=a;
        a*=a;
        a%=md;
        res%=md;
        b>>=1;
    }
    return res;
}
 
 
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef Triple<int, int, int> tiii;
 
 
const double EPS=0.000000001;
const double INFD32=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;
const ll one=1;
 
#define  maxN 100100
 
int arr[maxN];
 
vector<int> VEC[65];
 
vector<int> G[maxN];
int n;
 
bool vis[maxN];
int dist[maxN];
int bfs(int v,int tt){
    queue<int> q;
    for (int i=1; i<=n; ++i){
        vis[i]=0;
        dist[i]=0;
    }
    q.push(v);
    dist[v]=1;
    while (q.size()) {
        v=q.front();
        q.pop();
        for (int to:G[v]){
            if (!vis[to]){
                vis[to]=1;
                dist[to]=dist[v]+1;
                q.push(to);
            }
        }
    }
    if (!vis[tt]) return INF32;
    else return dist[tt];
}
 
int f(vector<pii> &ed,int k){
    vector<int> V1=G[ed[k].first];
    vector<int> V2=G[ed[k].second];
    G[ed[k].first].clear();
    G[ed[k].second].clear();
    for (int i:V1){
        if (i!=ed[k].second) G[ed[k].first].push_back(i);
    }
    for (int i:V2){
        if (i!=ed[k].first) G[ed[k].second].push_back(i);
    }
    int x= bfs(ed[k].first,ed[k].second);
    G[ed[k].first]=V1;
    G[ed[k].second]=V2;
    return x;
}
 
signed main(void){
    //look at the end
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n;
    for (int i=1; i<=n; ++i){
        cin>>arr[i];
        if (arr[i]==0){
            --i;
            --n;
            continue;
        }
        for (int j=0; j<=60; ++j){
            if (arr[i]&(one<<j)) VEC[j].push_back(arr[i]);
        }
    }
    for (int i=0; i<65; ++i){
        if (VEC[i].size()>2){
            cout<<3<<en;
            return 0;
        }
    }
    vector<pii> edges;
    for (int i=1; i<=n; ++i){
        for (int j=i+1; j<=n; ++j){
            if (arr[i]&arr[j]){
                edges.push_back({i,j});
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    int ans=INF32;
    for (int i=0; i<edges.size(); ++i){
        ans=min(ans,f(edges,i));
    }
    if (ans==INF32) cout<<-1<<en;
    else cout<<ans<<en;
    return 0;
}