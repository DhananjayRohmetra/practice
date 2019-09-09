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
	int s=0,i;
	string str1,str;
cin>>str;
cin>>str1;
for(i=0;i<str.length();i++)
{
	
	if((str[i]=='a'|| str[i]=='e'|| str[i]=='i'|| str[i]=='o'|| str[i]=='u') && (str1[i]=='a'|| str1[i]=='e'|| str1[i]=='i'|| str1[i]=='o'|| str1[i]=='u'))
	{
		s++;
	}
	
	if((str[i]!='a' && str[i]!='e'&& str[i]!='i'&& str[i]!='o' && str[i]!='u') && (str1[i]!='a'&& str1[i]!='e'&& str1[i]!='i'&& str1[i]!='o' && str1[i]!='u'))
	{
		s++;
	}
	
}
if(s==str.length() && s==str1.length())
{
	cout<<"Yes";
}
else
{
	cout<<"No";
}
	return 0;
}

