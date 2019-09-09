#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int  n,k;
	cin>>n>>k;
    if(k==1)
    {
    	cout<<"1";
	}
	if(k==2)
	{
		cout<<(1+(n*(n-1))/2);
	}
	if(k==3)
	{
			cout<<(1+(n*(n-1))/2+(n*(n-1)*(n-2))/3);
	}
	if(k==4)
	{
		cout<<(1+(n*(n-1))/2+(n*(n-1)*(n-2))/3+(3*n*(n-1)*(n-2)*(n-3))/8);
	}
}
//584811251
