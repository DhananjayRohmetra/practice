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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		int n,low,high,maxlength,start,i;
  		cin>>str;
  		n=str.length();
  		start=0;
  		maxlength=1;
  		for(i=1;i<n;i++)
  		{
  		//even length palindromes
  		low=i-1;
  		high=i;
		while(low>=0 && high<n && str[low]==str[high])
		{
		if(high-low+1>maxlength)
		{
			start=low;
			maxlength=high-low+1;
		}
		low--;
		high++;	
		}
		
		//odd length palindromes considering i as the centre
		low=i-1;
		high=i+1;
		while(low>=0 && high<n && str[low]==str[high])
		{
		if(high-low+1>maxlength)
		{
			start=low;
			maxlength=high-low+1;
		}
		low--;
		high++;	
		}	
		}
		//cout<<maxlength<<"\n";
		
		int sieve[10009];
		memset(sieve,0,sizeof(sieve));
		sieve[1]=1;
		for(i=2;i*i<=10000;i++)
		{
			if(sieve[i]==0)
			{
				for(int j=2*i;j*j<=10000;j+=i)
				{
					sieve[j]=1;
				}
			}
		}
		if(sieve[maxlength]==0)
		{
			cout<<"PRIME\n";
		}
		else
		{
			cout<<"NOT PRIME\n";
		}
	}
}



