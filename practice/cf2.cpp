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
	int t;
	cin>>t;
	while(t--)
	{
   int n;
   cin>>n;
   int s=1;
   int i,j,f=1;
   int dp[1008][1008];
   memset(dp,0,sizeof(dp));
   for(i=1;i<=1000;i++)
   {
   	dp[i][s]=f;
   	f++;
   	dp[i][s+1]=f;
   	f++;
   	s++;
   }
   if(n%2!=0) cout<<n/2+1;
   else
   cout<<n/2;
   for(i=1;i<=1000;i++)
   {
   	for(j=1;j<=1000;j++)
   	{
   	if(dp[i][j]!=0 && dp[i][j]<=n)
	   {
	   	cout<<i<<" "<<j<<"\n";
		}	
	}
   }
   

	}
}



