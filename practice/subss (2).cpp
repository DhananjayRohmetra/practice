#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin); 
	int n,k;	cin>>n>>k;
	int brr[n+1],up=n;
	for(int i=0;i<n;i++)	{cin>>brr[i];}
	sort(brr,brr+n);
	for(int i=0;i<n;i++)	{up+=upper_bound(brr,brr+n,brr[i]+k)-1-brr-i;}
	cout<<up;
}



