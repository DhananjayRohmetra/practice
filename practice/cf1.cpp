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
	
   int x,y,z;
   cin>>x>>y>>z;
   if(abs(x-y)<=z && z!=0)
   {
   	cout<<"?";
   }
   else if(x-y==0 && z==0)
	{
		cout<<"0";
	}
	else if(x-y>z)
	{
		cout<<"+";
	}
	else if(y-x>z)
	cout<<"-";
	
}



