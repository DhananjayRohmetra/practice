#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
int n,i,j,s=0;
cin>>n;
char str[n+2][n+2];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cin>>str[i][j];
	}
}

for(i=1;i<n-1;i++)
{
	for(j=1;j<n-1;j++)
	{
		if(str[i-1][j-1]=='X' && str[i-1][j+1]=='X' && str[i+1][j-1]=='X' && str[i+1][j+1]=='X' )
		{
			s++;
		}
	}
}
cout<<s;
	return 0;
}

