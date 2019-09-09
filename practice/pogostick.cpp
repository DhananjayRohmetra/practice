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
#define all(v) v.begin(),v.end()
int arr[100009],n;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j,sum=0,ans=-1e8,visited[100009],pref[100009],xx;
		vector<int>vec;
		cin>>n>>k;
		memset(visited, 0 ,sizeof(visited));
		for(i=0;i<n;i++)
		{
			cin>>arr[i];	
		}
			ans=-1e8;
		for(int ii=0;ii<n;ii++)
		{
			
			//cout<<visited[i]<<i<<endl;
			
			if(visited[ii]==0)
			{
			for(j=ii;j<n;j+=k)
			{
				//cout<<j<<" ";
				vec.push_back(arr[j]);
				visited[j]=1;
			}
			pref[vec.size()-1]=vec[vec.size()-1];
		
			ans=max(pref[vec.size()-1],ans);
			for(i=vec.size()-2;i>=0;i--)
			{
				pref[i]=pref[i+1]+vec[i];
				ans=max(pref[i],ans);
			}
		
	
			for(i=0;i<vec.size();i++)
			{
				pref[i]=0;
			}
			vec.clear();
			}
			
		}
		cout<<ans<<"\n";
	}
}


