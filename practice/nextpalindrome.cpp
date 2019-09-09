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
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--)
	{
		string str,ans,s;
		int flag=0,p=0,brakeflag=0,i,j;
		cin>>s;
		int slen=s.length(),flaglen=0;
				for(i=0;i<slen;i++)
				{
					if(s[i]!='0')
					{
						break;
					}
					else
					{
						flaglen++;
					}
				}
				str.resize(slen-flaglen);
				for(j=flaglen;j<slen;j++)
				{
					str[j-flaglen]=s[j];
				}
				
		int l=str.length();
		
		ans.resize(l+1);
		for(i=0;i<l;i++)
		{
			if(str[i]=='9')
			{
				p++;
			}
		}
		if(p==l)
		{
			for(i=0;i<l+1;i++)
			{
				if(i==0 || i==l)
				{
					ans[i]='1';
				}
				else
				{
					ans[i]='0';
				}
				cout<<ans[i];
			}
			break;
		}
		if(l%2==0)
		{
		int p=0;
		for(i=0;i<l/2;i++)
		{
			if(str[i]=='9')
			{
				p++;
			}
		}
		if(p==l/2)
		{
			for(i=0;i<l;i++)
			{
				ans[i]='9';
				cout<<ans[i];
			}
			break;
		}
		
		}
		if(l%2!=0)
		{
		
		for(i=0;i<l/2+1;i++)
		{
			if(str[i]=='9')
			{
				p++;
			}
		}
		if(p==l/2+1)
		{
			for(i=0;i<l;i++)
			{
				ans[i]='9';
			}
		}
		
		}
		for(i=0;i<l/2;i++)
		{
			if(str[i]==str[l-i-1] || l-i-1 - i==1)
			{
			
				if(l-i-1 - i==1)
				{
					if( str[i]!='9' && str[l-i-1]!='9')
					{
					
					if(str[i]<=str[l-i-1])
					{
						str[i]=str[i]+1;
					}
						str[l-i-1]=str[i];
					}
				else
				{
				
					for(j=i;j>=0;j--)
					{
						int pp=0;
					
						if(str[j]==str[l-j-1] && str[j]=='9')
						{
							
							str[j]='0';
							str[l-j-1]='0';	
							pp=1;
						}
						else if(str[j]==str[l-j-1] && pp!=1)
						{
							str[j]=str[j]+1;
							str[l-j-1]=str[j];
							brakeflag=1;
							break;	
						}		
					}
					if(brakeflag==1)
					break;
				}
				if(brakeflag==1)
					break;
				}
			}
			else
			{
				
				str[l-i-1]=str[i];
				flag=1;
			}
		}
		
		if(l%2!=0)
		{
				
			if(str[l/2]!='9')
			{
				str[l/2]=str[l/2]+1;	
			}
			else
			{
				if(str[l/2-1]=='9')
				{
					str[l/2]='9';
				}
				else
				{
					str[l/2]='0';
				}
				i=l/2-1;
				for(j=i;j>=0;j--)
					{
						if(str[j]==str[l-j-1] && str[j]=='9')
						{
						str[j]='9';
						str[l-j-1]='9';	
						}
						else
						{
							str[j]=str[j]+1;
							str[l-j-1]=str[j];
							brakeflag=1;
							break;
						}		
					}
				
			}
		
		}
	
		cout<<str<<"\n";
	}
}



