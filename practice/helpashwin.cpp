#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int s,n,m;
int indexar[100009][5];
int brr[100009][5];
vector<vector<int > >arr;
vector<vector<int > >dp;
int recur(int col,int row)
{
	if(row>=n) 
	{
		return 0;
	}
	if(dp[row][col]!=-1)
	 return dp[row][col];
	for(int i=1;i<=2;i++)
	{
		if(indexar[row+1][i]!=indexar[row][col])
		{
			dp[row][col]=max(dp[row][col],brr[row+1][i]+recur(i,row+1));
		}
	}
	return dp[row][col];
}
int main()
{
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int ans=0,i,j;
	scanf("%d %d",&n,&m);
	dp.resize(n+9);
for (ll i = 0; i < n+9; ++i)
    dp[i].resize(m+9);
 
	arr.resize(n+9);
for (ll i = 0; i < n+9; ++i)
    arr[i].resize(m+9);
for(i=0;i<=n+1;i++)
{
	for(ll j=0;j<=m+1;j++)
	{
		dp[i][j]=-1;
	}
}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for(j=1;j<=n;j++){
	
	
	int index,index2,maxx=-1;
	for(i=1;i<=m;i++)
	{
		if(arr[j][i]>maxx)
		{
			index=i;
			maxx=arr[j][i];
		}
	}
	int max1=-101;
	for(i=1;i<=m;i++)
	{
		if(arr[j][i]>max1 && i!=index)
		{
			index2=i;
			max1=arr[j][i];
		}
	}
	indexar[j][1]=index;
	indexar[j][2]=index2;
	brr[j][1]=arr[j][index];
	brr[j][2]=arr[j][index2];
	}
	ans=max(ans,recur(1,0));
    printf("%d\n",ans);
	}
}
 
 
