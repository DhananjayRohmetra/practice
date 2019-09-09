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
	int n,q,i,j,x,y;
	cin>>n>>q;
	int visited[5009];
	vector<pair<int,int> >vec;
	for(i=0;i<q;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vec.pb({x,y});
		for(j=vec[i].first;j<=vec[i].second;j++)
		{
			visited[j]++;
		}
	}
	int answer=-1;
	for(i=0;i<q;i++)
	{
		int ones[5009];
		for(j=0;j<5009;j++)
		{
			ones[j]=0;
		}
		int countpos=0;
		for(j=vec[i].first;j<=vec[i].second;j++)
		{
			visited[j]--;
		}
		for(j=0;j<n;j++)
		{
			if(visited[j]>0)
			{
			countpos++;
			}
			if(visited[j]==1)
			{
				ones[j]++;
			}
		}
		for(j=1;j<n;j++)
		{
			ones[j]+=ones[j-1];
		}
		
		for(j=i+1;j<q;j++)
		{
			int toolow;
			int l=vec[j].first,r=vec[j].second;
		if(l==0)
		{
			toolow = ones[r];
		}
		else
		{
			toolow = ones[r]-ones[l-1];
		}
	
		answer=max(answer,countpos-toolow);
		}
		for(j=vec[i].first;j<=vec[i].second;j++)
		{
			visited[j]++;
		}
	}
	cout<<answer;
}

