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
int dp[100][100],visited[100][100];
int go(int i,int j,string &s)
{
	if(i>=j)
	return 1;
	
	if(visited[i][j]!=0)
	return dp[i][j];
	
	visited[i][j]=1;
	if(s[i]!=s[j])
	return 0;
	
	return dp[i][j]=go(i+1,j-1,s);
}
int main()
{
string str;
cin>>str;
int i,j,n=str.length(),ans=0; 

for(i=0;i<n;i++)
{
	for(j=i;j<n;j++)
	{
		ans+=go(i,j,str);
	}
}
cout<<ans;
}



