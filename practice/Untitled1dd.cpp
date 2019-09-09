#include<bits/stdc++.h>
using namespace std;
int hash[100002];
int main()
{
	int n,m,i,e=0,s=0,ans=-1,j,vrr[100002],k=1;
	cin>>n>>m;
	int arr[n+2];
	for(i=1;i<=m;i++)
	{
		cin>>arr[i];
		vrr[i]=1;
	}
for(i=1;i<=m;i++)
{
cout<<hash[arr[i]];
if(hash[arr[i]]<k){

	hash[arr[i]]++;
	s++;
    
    }
	if(s==n)
    {
    	k++;
    	vrr[i]=1;
    	s=0;
	}
	else
	{
		vrr[i]=0;
	}
    
	
}
for(i=1;i<=m;i++)
{
//	cout<<vrr[i];
}
}
