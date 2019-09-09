#include<bits/stdc++.h>
using namespace std;
int d=0;
void recur(int r,int c,int f,int k);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,k,f=0;
		cin>>a>>b>>k;
	recur(a,b,f,k);
	}
}
void recur(int r,int c,int f,int k)
{
	if((r<1 || r>8)||(c<1 || c>8))
	{
		return;
	}
	else
	{
		if(f==k)
		{
			d++;
			return;
		}
	cout<<r<<" "<<c<<endl;
	recur(r+1,c,f++,k);
	recur(r+1,c+1,f++,k);
	recur(r+1,c-1,f++,k);
	recur(r-1,c,f++,k);
	recur(r-1,c+1,f++,k);
	recur(r-1,c-1,f++,k);
	recur(r,c+1,f++,k);
	recur(r,c-1,f++,k);
}
}
