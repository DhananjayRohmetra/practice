#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
int visited[29][29],n,f=0;
void recur(int i,int j)
{
	//cout<<i<<" "<<j<<endl;
	if(i>n){
		
		f++;
		return;
	}
	if(i>1 && j>1)
	{
		if( visited[i-1][j-1]==1 || visited[i+1][j+1]==1 || visited[i+1][j-1]==1 || visited[i-1][j+1]==1)
		{
			return;
		}
	}
	if(i>1 && j==1)
	{
		if(visited[i+1][j+1]==1  || visited[i-1][j+1]==1)
		{
			return;
		}
	}
	if(i==1 && j>1)
	{
		if( visited[i+1][j+1]==1 || visited[i+1][j-1]==1 )
		{
			return;
		}
	}
	if(i==1 && j==1)
	{	
	if( visited[i+1][j+1]==1 )
		{
			return;
		}
	}
	for(int l=1;l<=n;l++)
	{
		if(visited[i][l]==1)
		{
			return ;
		}
	}
	for(int l=1;l<=n;l++)
	{
		if(visited[l][j]==1)
		{
			return;
		}
	}
	
	if(visited[i][j]==0)
	{
		visited[i][j]=1;
		
		if(i==4)
		{
			recur(i+1,1);
		}
		else
		{
		
		for(int k=1;k<=n;k++)
		{
			recur(i+1,k);
			visited[i+1][k]=0;
			
		}
	}
	}
	
}
int main()
{
	cin>>n;
	memset(visited, 0 ,sizeof(visited));
	for(int i=1;i<=n;i++){
	
	recur(1,i);
	visited[1][i]=0;}
	cout<<f;
	return 0;
}


