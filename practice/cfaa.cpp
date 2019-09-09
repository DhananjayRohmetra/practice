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
	int i,n,m;
   	cin>>n>>m;
   	int aaa[108],ans[n+1],x,gg,ii;
   	memset(aaa,0,sizeof(aaa));
   	for(i=0;i<n;i++)
   	{
   		
   		cin>>x;
   		
   		if(i==0)
   		{
   		ans[i]=0;	
		}
		else
		{
			int g=0,flag=0,cnt=0,gg;
			for(ii=1;ii<=100;ii++)
			{
				g+=ii*aaa[ii];
				cnt+=aaa[ii];
				//cout<<g<<"\n";
				if(g>m-x)
				{
					g-=ii*aaa[ii];
				 gg=ii;
					flag=1;
					cnt-=aaa[ii];
					break;
				}
				
			}
			if(flag==1)
			{
			//	cout<<g<<"\n";
			int  req=m-x-g;
			int res=req/gg;
			cnt+=res;
			}
			ans[i]=i-cnt;
	//		cout<<ans[i];
		}
   		aaa[x]++;
	}
	ans[0]=0;
  for(i=0;i<n;i++) 
 	cout<<ans[i]<<" ";
}



