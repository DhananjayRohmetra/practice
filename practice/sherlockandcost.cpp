#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
int dp[100009],n,arr[100009];
int recur(int val,int index)
{
	if(index>n)
	return 0;
	
	if(dp[index]!=-1)
	return dp[index];
	if(index!=n){
	dp[index]=max(abs(arr[index]-val)+recur(arr[index],index+1),abs(1-val)+abs(arr[index+1]-1)+recur(arr[index+1],index+2));}
else
{
dp[index]=max(abs(arr[index]-val),abs(1-val));
}
	return dp[index];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int i;
   	cin>>n;
   	
   	for(i=1;i<=n;i++)
   	{
   		cin>>arr[i];	
	}
	memset(dp,-1,sizeof(dp));
	cout<<max(recur(arr[1],2),abs(arr[2]-1)+recur(arr[2],3))<<"\n";


	}
}



