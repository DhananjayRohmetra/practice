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

int recur(int index,int number);
int dp[1000009][10],n;
string s;
int main()
{
	int i,s1=1,index,f=0;
	cin>>s;
	n=s.length();
	memset(dp,-1,sizeof(dp));
	recur(0,1);
	
	for(i=0;i<n;i++)
	{
		if(dp[i][7]!=-1)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	cout<<0;
	else
	cout<<dp[0][1];
}

int recur(int index,int number)
{
	if(index>=n)
	return 0;
	
	if(dp[index][number]!=-1)
	return dp[index][number];
	
	if(number==1 && s[index]=='1'){
	dp[index][number]=max(1+recur(index+1,8),1+recur(index+1,1));
	 return dp[index][number];}
	 
	if(number==8 && s[index]=='8'){
	dp[index][number]=max(1+recur(index+1,0),1+recur(index+1,8));
	 return dp[index][number];}
	 
	if(number==0 && s[index]=='0'){
	dp[index][number]=max(1+recur(index+1,7),1+recur(index+1,0));
	 return dp[index][number];}
	 
	if(number==7 && s[index]=='7'){
	dp[index][number]=1+recur(index+1,7);
	return dp[index][number];}
	 
	return dp[index][number]=recur(index+1,number);
} 

