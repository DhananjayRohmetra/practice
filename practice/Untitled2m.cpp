#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		vector<pair< int ,int > >vec;
		int n,x,y,f=0,ans[100004],l,r,i;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>l>>r;
		    vec.push_back(make_pair(l,r));
	        ans[i]=1;	   
		}
	
		sort(vec.begin(),vec.end());
		r=-1;
		ans[0]=1;
		for(i=1;i<n;i++)
		{
			r=max(r,vec[i-1].second);
			if(vec[i].first<r)
			{
				ans[i]=ans[i-1];
			}
			else if(vec[i].first>r)
			{
				if(f==1)
				ans[i]=ans[i-1];
				else
				{
				
				if(ans[i-1]==1)
				{
					ans[i]=2;
					f=1;
				}
				else
				{
					ans[i]=1;
				}
			}
			}
			else
			{
				if(f==1)
				{
					ans[i]=ans[i-1];
				}
			}
		}
		int p=0;
		for(i=0;i<n;i++)
		{
	if(ans[i]==2)
	{
		p++;
	}
		}
		if(p==0)
		{
			cout<<"-1";
		}
		else
		{
			for(i=0;i<n;i++)
		{
	cout<<ans[i]<<" ";
		}
		}
	cout<<endl;
	}
}
