#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()

int main()
{
	int n,i,j,flag=0;;
	cin>>n;
	int ans[n+9];
	memset(ans,-1,sizeof(ans));
	int count=1;
	for(i=2;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			if(ans[j]==-1)
			{
				ans[j]=count;
				flag=1;
			}
		}
		if(flag==1)
		{
			flag=0;
		count++;
		}
	}
	for(i=2;i<=n;i++)
	cout<<ans[i]<<" ";
}



