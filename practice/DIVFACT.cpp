#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll prime[50002],make[6000];
void sieve();
int main()
{
	sieve();
/*ll t;
cin>>t;
while(t--)
{
	
}*/
		
}
void sieve()
{
ll i,j,m,s;
ll eprime[50002][5134];
	for(i=2;i*i<=50000;i++)
	{
		if(prime[i]==0)
		{
			
		for(j=2*i;j<=50000;j+=i)
		{
			prime[j]=1;
		}
		
	    }
	}
	j=0;
	for(i=2;i<=50000;i++)
	{
		if(prime[i]==0)
		{
			make[j]=i;
			j++;
		}
	}

	m=j;
for(i=2;i<=50000;i++)
{
	for(j=0;j<m;j++)
	{
		s=0;
		while((i%make[j])==0)
		{
			s++;
			i=i/make[j];
		}
		eprime[i][j]=s;
		if(i==24)
		{
			cout<<eprime[i][j];
		}
	}
	
}

}
