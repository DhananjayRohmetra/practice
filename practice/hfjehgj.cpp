#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()
int n;
int arr[100001],brr[100001],dp[100001][3];
int  recur(int index,int row)
{
	//cout<<index<<" "<<row<<"\n";
	if(index>=n)
	{
		return 0;
	}
	
	if(dp[index][row]!=0)
	{
	return dp[index][row];
	}
	
	if(row==-1)
	{
		
		dp[index][1]=arr[index]+recur(index+1,1);
		dp[index][2]=brr[index]+recur(index+1,2);
	}
	if(row==1)
	{
		dp[index][row]=max(recur(index+1,1),brr[index]+recur(index+1,2));
		return dp[index][row];
	}
	if(row==2)
	{
		dp[index][row]=max(recur(index+1,2),arr[index]+recur(index+1,1));
		return dp[index][row];
	}
	
}
signed main()
{
	
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>brr[i];
	}
	memset(dp,0,sizeof(dp));
	recur(0,-1);
	cout<<max(dp[0][1],dp[0][2]);
	
}



