#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
	int n; cin>>n;
	long long int  arr[n+1],minn,maxx,temp_minn,temp_maxx,i;
	for(i=1;i<=n;i++) cin>>arr[i];
	maxx=minn=arr[1];
	for(i=2;i<=n;i++)
	{	temp_maxx=maxx;
		temp_minn=minn;
			maxx=  max(max(temp_minn-arr[i],max(temp_minn*arr[i],temp_minn+arr[i])),max(temp_maxx-arr[i],max(temp_maxx*arr[i],temp_maxx+arr[i])));	
			minn=  min(min(temp_minn-arr[i],min(temp_minn*arr[i],temp_minn+arr[i])),min(temp_maxx-arr[i],min(temp_maxx*arr[i],temp_maxx+arr[i])));
	}
	cout<<minn<<endl;
	}
}

