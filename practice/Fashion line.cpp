#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,l,r,i,j;
		string str,btr;
		cin>>n>>k>>l>>r;
		cin>>str;
		cin>>btr;
		int z[n+6],freq[n+6];
		for(i=0;i<str.length();i++)
		{
		freq[i]=0;}
		
		for(i=0;i<str.length();i++)
		{
			for(j=0;j<btr.length();j++)
			{
				if(str[i]==btr[j])
				{
					if(i==0)
					{
					 z[i]=1;
					}
					else{
					
					z[i]=z[i-1]+1;}
					break;
				}
			}
			if(j==btr.length())
			{
					if(i==0)
					{
					 z[i]=0;
					}
					else{
					
					z[i]=z[i-1];}
			}
		}
		for(i=0;i<str.length();i++)
		{
			freq[z[i]]++;
		}
		for(i=0;i<str.length();i++)
		{
		c[i]=z[str.length()-i-1];
		}
		for(i=str.length()-1;i>=0;i--)
		{
			
		}
		
	}
}
