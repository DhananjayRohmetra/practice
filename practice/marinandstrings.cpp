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
vector<char>vec;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
stack<pair<char,int> >st;

int n,i,s=0,l,k,m,d;
char str[100008];
while(!st.empty())
{
	st.pop();
}
char ch='o';
st.push({ch,0});
cin>>str;
cin>>k;
vec.clear();
  l=strlen(str);
for(i=0;i<l;i++)
{
	if(str[i]!=st.top().second)
	{
		d=1;
		st.push({str[i],d});
	}
	else if(str[i]==st.top().first)
	{
		d=st.top().second+1;
		st.push({str[i],d});
		
			if(st.top().second==k)
			{
			while(st.top().second!=1)
			{
		      st.pop();
		    }
		    st.pop();
		    }		
	}
}
while(!st.empty())
{
	vec.push_back(st.top().second);
	st.pop();
}
reverse(vec.begin(),vec.end());
for(i=1;i<vec.size();i++)
{
	cout<<vec[i];
}
cout<<"\n";
}
}
