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

int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
ll n,k;
cin>>n>>k;
ll zero=0,one=1,ans=9223372036854775808;
ll prefix[n+9],arr[n+9],i,xrr[n+9],brr[n+9],index=0;
map<ll,ll>mp1;
for(i=1;i<=n;i++)
{
	cin>>brr[i];
	arr[i]=brr[i];
}
sort(arr+1,arr+n+1);
memset(prefix,0,sizeof(prefix));
for(i=1;i<=n;i++)
{
	prefix[i]=arr[i]+prefix[i-1];
}

for(i=1;i<=n;i++)
{
	xrr[i]=prefix[n]-prefix[i]-(n-i)*arr[i]+(i-1)*arr[i]-prefix[i-1];
	if(xrr[i]<k)
	{
		if((k-xrr[i])%2==0)
		{
			xrr[i]=0;
			mp1[arr[i]]=0;
			ans=min(ans,zero);
		}
		else{
			xrr[i]=1;
			mp1[arr[i]]=1;
			ans=min(ans,one);
		}
	}
	else
	{
		mp1[arr[i]]=xrr[i]-k;
		ans=min(ans,xrr[i]-k);
	}
}
for(i=1;i<=n;i++)
{
	if(mp1[brr[i]]==ans)
	{
		index=i;
		break;
	}
}
cout<<index<<" "<<ans;

}



