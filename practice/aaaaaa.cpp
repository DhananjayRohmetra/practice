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
int n;
cin>>n;
int cnt=0;
int i=1;
while(cnt!=2*n)
{
	
	if(i != 0 && (i+n)%(2*n)!=0){
	
	cout<<i<<" "<<(i+n)%(2*n)<<" ";}
	else if(i ==0)
	{
		cout<<2*n<<" "<<(i+n)%(2*n)<<" ";
	}
	else
	{
		cout<<i<<" "<<2*n<<" ";
	}
	cnt+=2;
	i=(i+n+1)%(2*n);
}
 
}
 
