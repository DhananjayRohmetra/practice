#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
int t;
cin>>t;
while(t--)
{
ll n,q,i,x,y,r,dist,j,min1,max1;
cin>>n>>q;
ll xrr[n+2],yrr[n+2],rrr[n+2],prefix[1000008];
  for(i=0;i<n;i++)
  {
  	cin>>x>>y>>r;
  	xrr[i]=x;
  	yrr[i]=y;
  	rrr[i]=r;
  	prefix[i]=0;
  }
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		dist=sqrt((xrr[j]-xrr[i])*(xrr[j]-xrr[i])+(yrr[j]-yrr[i])*(yrr[j]-yrr[i]));
		if(xrr[i]==xrr[j] && yrr[i]==yrr[j] && rrr[i]==rrr[j])
		{
			prefix[rrr[i]]++;
			prefix[rrr[i+1]]--;
		}
		else if(dist<max(rrr[i],rrr[j]))
		{
			min1=max(rrr[i],rrr[j])-min(rrr[i],rrr[j])-dist;
			max1=rrr[i]+rrr[j]+dist;
				prefix[min1]++;
				prefix[max1+1]--;
		}
		else
		{
			min1=abs(rrr[i]+rrr[j]-dist);
			max1=rrr[i]+rrr[j]+dist;
				prefix[min1]++;
				prefix[max1+1]--;
		}
	}
}
for(i=0;i<n;i++)
{
	cout<<prefix[i]<<" ";
}


}
}

