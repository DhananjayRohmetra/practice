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
	fast;
	string a,b;
	cin>>a>>b;
	ll alength,blength,i,j,l,r;
	alength=a.length();
	ll arr[27],pref[27][alength+1];
	memset(arr,0,sizeof arr);
	blength=b.length();
	for(i=0;i<blength;i++)
	{
		arr[b[i]-'a'+1]++;
	}
	
	memset(pref, 0 ,sizeof pref);
	pref[a[0]-'a'+1][0]=1;
	for(j=1;j<=26;j++)
	{
		for(i=1;i<alength;i++)
		{
			pref[j][i]=pref[j][i-1];
			pref[a[i]-'a'+1][i]=pref[a[i]-'a'+1][i-1]+1;
			
		}
	}
	
	
	int q;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		ll count=0;
		for(i=1;i<=26;i++)
		{
			if(pref[a[i]-'a'+1][r]-pref[a[i]-'a'+1][l-1]<arr[a[i]-'a'+1])
			{
				count+=(arr[a[i]-'a'+1]-(pref[a[i]-'a'+1][r]-pref[a[i]-'a'+1][l-1]));
			}
			
			if(pref[a[i]-'a'+1][r]-pref[a[i]-'a'+1][l-1]>arr[a[i]-'a'+1])
			{
				count+=(-1*arr[a[i]-'a'+1]+(pref[a[i]-'a'+1][r]-pref[a[i]-'a'+1][l-1]));
			}
			
		}
		cout<<count<<endl;
	}

}

