#include<bits/stdc++.h>
using namespace std;
int z[100];
int main()
{
	string s,pattern,word;
	cin>>pattern;
	cin>>word;
	s=pattern+'$'+word;
	int left=0,right=0,k1;
for(int k=1;k<s.length();k++)
{
	if(k>right)
	{
		left=right=k;
		while(right<s.length() && s[right]==s[right-left])
		{
			right++;
		}
	z[k]=right-left;
	right--;	
	}
	else
	{
k1=k-left;
if(z[k1]<right-k+1)
{
	z[k]=z[k1];
}
else
{
	left=right=k;
	while(right<s.length() && s[right]==s[right-left])
	{
		right++;
	}
		z[k]=right-left;
	right--;
	
	
}
	}
}

for(int i=0;i<s.length();i++)
{
	cout<<z[i]<<" ";
}
}
