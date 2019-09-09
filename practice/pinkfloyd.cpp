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
	int n,i;
	cin>>n;
	int cnt=1,ans=0,x;
	stack<int>st;
	st.push(-1);
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x==cnt)
		{
			ans++;
			cnt++;
			if(st.top()==cnt)
			{
				while(st.top()==cnt)
				{
					ans++;
					st.pop();
					cnt++;
				}
			}
		}
		else
		{
			st.push(x);
		}
	}
	if(ans==n) cout<<"Happy";
	else
	{
		cout<<"Sad";
	}
}



