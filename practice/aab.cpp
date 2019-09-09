#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,maxx=-1,ans=0,i,j;
	cin>>n;
	int arr[n+2];
	for(i=1;i<=n;i++)
	cin>>arr[i];

	for(i=1;i<=n;)
{

	if(arr[i]==i)
	{
	//	cout<<i<<endl;
		ans++;
		i++;
	}
	else
	{
		for(j=i;j<=arr[i];j++)
		{
			i=max(i,max(j,arr[j]));
		}
	}
}

cout<<ans;
	return 0;
}

