#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	ll n,m,i,j,flag=0;
	cin>>n>>m;
	char str[1009][1009];
	ll arr[1009][1009];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		
		cin>>str[i][j];
		if(str[i][j]=='#')
		{
			arr[i][j]=-1;
		}
		else
		arr[i][j]=0;
	}
	}
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		
		if(arr[i][j]!=-1)
		{
			if((arr[i+1][j]!=0 || arr[i][j-1]!=0 || arr[i+1][j-1]!=0) && (arr[i-1][j]!=0 || arr[i-1][j-1]!=0 || arr[i][j-1]!=0)&& (arr[i-1][j]!=0 || arr[i][j+1]!=0 || arr[i-1][j+1]!=0) && (arr[i+1][j]!=0 || arr[i][j+1]!=0 || arr[i+1][j+1]!=0))
			{
				flag=1;
			}
		}
	}
	}
	if(flag==1)
	cout<<"no\n";
	else
	cout<<"yes\n";
}
}
