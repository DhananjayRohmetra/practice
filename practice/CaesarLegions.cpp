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
ll recur (ll curr,ll count1,ll count2);
ll n1,n2,k1,k2,dp[3][101][101],consec1,consec2,f=0;
int main()
{
	ll ans;
cin>>n1>>n2>>k1>>k2;
for(ll i=1;i<=2;i++)
{
	for(ll j=0;j<=100;j++)
	{
		for(ll k=0;k<=100;k++)
 {
						dp[i][j][k]=-1;	
		}
	}
}
ans=recur(2,0,1);
cout<<dp[2][0][1];
	return 0;
}
ll recur (ll curr,ll count1,ll count2)
{
	if(curr==1)
	{
		consec1++;
		consec2=0;
	}
	else
	{
		consec2++;
		consec1=0;
	}
	cout<<curr<<" "<<count1<< " "<<count2<<" "<<consec1<<" "<<consec2<<endl;
		if(count1+count2==n1+n2)
	{
		
	dp[curr][count1][count2]=1;
	return dp[curr][count1][count2];
		
	}
	if(dp[curr][count1][count2]!=-1)
	return dp[curr][count1][count2];
	if(count1>n1 || count2>n2)
	return 0; 
	

	
	if(consec1>k1)
	{
	consec1=0;
	
    }
    
   	if(consec2>k2)
	{
	consec2=0;
	
    }
	
	dp[curr][count1][count2]=recur(1,count1+1,count2)+recur(2,count1,count2+1);
}

