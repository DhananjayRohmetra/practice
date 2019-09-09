#include <bits/stdc++.h>
using namespace std;

int main()
{
freopen("input.txt", "r", stdin);
int t;
cin >> t;
while(--t>=0)
{
int n,x,i,flag=0,x1,x2,ans=0,s1,s2;
cin >> n >> x;
int a[n+1];
multiset <int,greater<int>> s;
for(i=1;i<=n;i++)
{
cin >> a[i];
s.insert(a[i]);
}
if(n==1)
{
	if(x>*s.begin())
	{
		  cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
}
else
{
	while(!s.empty())
	{
		if(flag==0)
		{
			x1=*s.begin();
			//cout<<x1;
			s.erase(s.begin());
			x2=*s.begin();
			s.erase(s.begin());
			flag=1;
		}
		else
		{
			s1=x1;
			s2=x2;
					//	cout<<s1<<" "<<s2<<"\n";

			if(s1==s2)
			{
				ans+=s1;
				if(s.size()>1)
				{
					
					x1=*s.begin();
					s.erase(s.begin());
					x2=*s.begin();
					s.erase(s.begin());
				}
				else
				{
					cout<<s.size();
					if(s.size()==1)
					{
						
						ans+=*s.begin();
						s.erase(s.begin());
					}
				}
			}
			else
			{
				if(s1>s2)
				{
					ans+=s2;
					x1-=s2;
					
					x2=*s.begin();
					s.erase(s.begin());
				}
				if(s1<s2)
				{
					ans+=s1;
					x2-=s1;
					
					x1=*s.begin();
					s.erase(s.begin());
				}
			}
		}
		
	}
	if(x1!=0 && x2!=0)
	{
		ans+=max(x1,x2);
	}
	if(x>=ans)
cout<<"Yes\n";
else
{

	cout<<"No\n";
}
}

s.clear();
}
}
