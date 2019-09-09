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
ll sieve[109],dp[20][2][200][200],ansl=0;

ll recur(ll arr[],ll even,ll odd,ll index,ll tight,ll len,ll k)
	{
	
	if(index==len)
		{
			if(even-odd>=0)
			{
				if(sieve[even-odd]==0)
				{
						
						ansl++;
						return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			return 0;
		}
	
		if(dp[index][tight][even][odd]!=-1)
	return dp[index][tight][even][odd];
	
	ll ret=0;
	
if(tight)
{
	k=arr[index];
}
else
{
	k=9;
}
for(ll i=0;i<=k;i++)
{
	ll newtight;
	if(arr[index]==i)
	{
	 	newtight=tight;
	}
	else
	{
		newtight=0;
	}
	if((len-index)%2==0)
	{
		ret+=recur(arr,even+i,odd,index+1,newtight,len,k);
	}
	else
	{
		ret+=recur(arr,even,odd+i,index+1,newtight,len,k);
	}
}
dp[index][tight][even][odd]=ret;
return dp[index][tight][even][odd];
}
int main()
{
	for(int i=2;i<=1000;i++)
	{
		for(int j=2*i;j<=1000;j+=i)
			{
				if(sieve[i]==0)
						{
							sieve[j]=1;				
						}		
			}	
	}
	sieve[0]=sieve[1]=1;
int t;
cin>>t;
while(t--)
{
	ll a,b,i=0,j,ans;
	cin>>a>>b;

	ll arr[11],brr[11],c;
	c=a-1;
		memset(arr , 0 , sizeof arr);
		while(c!=0)
		{
			arr[i]=c%10;
			c/=10;
			i++;
		}

		for(j=0;j<i/2;j++)
		{
			swap(arr[j],arr[i-1-j]);
		}
		memset(dp , -1 , sizeof dp);
		//cout<<ansl;
		ansl=0;
ans=recur(arr,0,0,0,1,i,0);
//cout<<ansl;
ll mm=ansl;


i=0;
memset(arr , 0 , sizeof arr);
	while(b!=0)
		{
			arr[i]=b%10;
			b/=10;
			i++;
		}
		for(j=0;j<i/2;j++)
		{
			swap(arr[j],arr[i-1-j]);
		}
		memset(dp , -1 , sizeof dp);
		//cout<<ansl;
		ansl=0;
		
ans=recur(arr,0,0,0,1,i,0);
cout<<ansl-mm<<"\n";                                                                                                      

}


}

