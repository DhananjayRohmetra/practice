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
int main()
{
	int sieve[1000003]={0},i,j,q,x,d=0,count1[1000009]={0},ans=1;
	set<int>st;
for(i=2;i*i<=1000000;i++)
{
	if(sieve[i]==0){
	
	for(j=i;j<=1000000;j+=i)
	{
		if(sieve[j]==0)
		{
		
		sieve[j]=i;
		}		
	}
  }
}
cin>>q;
while(q--)
{
	cin>>x;
	st.clear();
	while(x!=0)
	{
		st.insert(sieve[x]);
		x=x/sieve[x];
		count1[sieve[x]]++;
	}
	for (set<int>::iterator it=st.begin(); it!=st.end(); ++it)
   {
   	ans*=(count1[*it]+1);
   }
   ans-=st.size();
	cout<<ans<<"\n";
}
	return 0;
}

