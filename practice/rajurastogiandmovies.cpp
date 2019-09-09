#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
int main()
{
    //freopen("input.txt", "r", stdin);
	ll n,x,i,anss=-1;
	cin>>n>>x;
	ll arr[n+2];

	for(i=0;i<n;i++)
	cin>>arr[i];
	
	ll high=1000000000;
	ll low=0,mid;
	while(low+10<=high)
	{
		mid=low+(high-low)/2;
	
		ll ans=0;
		for(i=0;i<n;i++)
		{
			if(mid<arr[i])
			{
				ans+=(arr[i]-mid);
			}
		}
		
		if(ans>=x)
		{
			anss=max(anss,mid);
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	for(ll ii=low;ii<=high;ii++)
	{
			ll ans=0;
		for(i=0;i<n;i++)
		{
			if(ii<arr[i])
			{
				ans+=(arr[i]-ii);
			}
		}
		if(ans>=x)
		{
			anss=max(anss,ii);
		}
	}
	cout<<anss;
	
}


