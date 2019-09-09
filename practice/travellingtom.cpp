#include <bits/stdc++.h>
using namespace std;
 
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define write(v)                       \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define read(v)                        \
    for (int i = 0; i < v.size(); i++) \
        cin >> v[i];
#define write1(v)                      \
    for (int i = 1; i < v.size(); i++) \
        cout << v[i] << " ";
#define read1(v)                       \
    for (int i = 1; i < v.size(); i++) \
        cin >> v[i];
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(v) v.begin(), v.end()
int p[100009][19], l[100009], mm[100009];
vector<vector<int>> adj;
void dfs(int s, int par)
{
    for (auto i : adj[s])
    {
        if (i != par)
        {
            l[i] = 1 + l[s];
            dfs(i, s);
            p[i][0] = s;
        }
    }
}
int getlca(int pp, int qq)
{
    if (l[pp] < l[qq])
    {
        swap(pp, qq);
    }
 
    int k, i;
    for (k = 1; (1 << k) <= l[pp]; k++)
        ;
    k--;
 
    for (i = k; i >= 0; i--)
    {
        if (l[pp] - (1 << i) >= l[qq])
        {
            pp = p[pp][i];
        }
    }
 
    if (pp == qq)
        return pp;
 
    for (i = k; i >= 0; i--)
    {
        if (p[pp][i] != p[qq][i] && pp[p][i] != -1)
        {
            pp = p[pp][i];
            qq = p[qq][i];
        }
    }
 
    return p[pp][0];
}
int findset(int x)
{
    if (parent[x] == x)
        return x;
    else
    {
 
        parent[x] = findset(parent[x]);
        return parent[x];
    }
}
int main()
{
 
   int t;
cin>>t;
for(int k=1;k<=t;k++)
{
int m,i,n,j,x,mm,xxx,yyy;
scanf("%d",&n);
adj.resize(n+1);
for(i=1;i<=n;i++)
{
scanf("%d",&m);
 
for(j=0;j<m;j++)
{
scanf("%d",&x);
adj[i].pb(x);
adj[x].pb(i);
}
}
 
memset(pp,-1,sizeof(pp));
dfs(1,-1);
for(j=0;(1<<j)<n;j++)
{
for(i=n;i>=1;i--){
 
if(pp[i][j]!=-1)
pp[i][j+1]=pp[pp[i][j]][j];
 
}
}
 
scanf("%d",&mm);
printf("Case %d:\n",k);
for(i=0;i<mm;i++)
{
scanf("%d %d",&xxx,&yyy);
printf("%d\n",getlca(xxx,yyy));
 
}
}
}
