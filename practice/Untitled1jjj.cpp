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

int main()
{
fast;
int t;
cin>>t;
while(t--)
{
	string str,ans;
	cin>>str;
	int arr[67],len,i,j;
	len=str.length();
	memset(arr, 0,sizeof(arr) );
	for(i=0;i<len;i++)
	{
		arr[str[i]-'a']++;
	}
	int s=0;
	for(i=0;i<26;i++)
	{
		if(arr[i]>0)
		{
			s++;
		}
	}
	if(s%2!=0)
	{
		int lenn=0;
		int anss;
		for(i=0;i<26;i++)
		{
			if(arr[i]>0)
			{
				anss=i;
				break;
			}
		}
			int cnt1=0,ans1;
		for(i=0;i<26;i++)
		{
			if(arr[i]>0)
			{
				cnt1++;
			}
			if(cnt1==s/2)
			{
			ans1=i;
			break;
			}
			
		}
		int cnt=0;
		for(i=0;i<26;i++)
		{
			if(arr[i]>0)
			{
				cnt++;
			}
			if(cnt==s/2+1)
			{
				if(abs(i-ans1)==1)
				{
					ans+=char(ans1+97);		
				}
			}
			
		}
		while(lenn<=len-1)
		{
			
		for(i=0;i<26;i++)
		{
			if(arr[i]>0)
			{
				for(j=1;j<=arr[i];j++)
				{
					ans+=char(i+97);
					lenn++;
				}
			}
		}
		for(i=25;i>0;i--)
		{
			if(arr[i]>0)
			{
				for(j=1;j<=arr[i];j++)
				{
					ans+=char(i+97);
					lenn++;
				}
			}
		}
	
	}
		cout<<ans;
	}
}

}


