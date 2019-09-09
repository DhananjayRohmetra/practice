#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,x,y,f=0,ans[100004],l,r,i;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>l>>r;
		
			if(i==0)
			{
			x=min(l,r);
			y=max(l,r);
		    }
		    if((l<x && r<x)||((l>y && r>y)))
		    {
		    	ans[i]=1;
		    	f=1;
		    		x=min(l,r);
			y=max(l,r);
			}
			else
			{
				ans[i]=2;
			}
		}
		if(f==0)
		{
			cout<<"-1\n";
		}
		else
		{
			for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
			
			cout<<endl;
		}
	}
}
