#include<bits/stdc++.h>
using namespace std;
int freq[200][9];
int main()
{
	int n,i,j,s1=0,f=0,s2=0,p[200],k=0,t,m;
	char str[200];
	
cin>>n;
cin>>str;	
for(i=0;i<n;i++)
{
	s1+=(str[i]-'0');
	k=0;
	p[k]=i;
	k++;
	for(j=i+1;j<n;j++)
	{
		s2+=(str[j]-'0');
		
		
		if(s2>s1)
		{
			s2=0;
			break;
		}
		if(j==n-1 && s1==s2)
		{
		
			f=1;
		}
		if(s1==s2)
		{
		s2=0;
	    p[k]=j;
	    k++;
	    	
		}
	}
	if(f==1)
	break;
}
for(i=0;i<k;i++)
cout<<p[i]<<" ";
if(f==1)
{
for(i=0;i<=p[0];i++)
{
	freq[0][str[i]-'0']++;
}
t=p[0];
for(j=1;j<k;j++)
{
for(i=t+1;i<=p[j];i++)
{
	for(m=0;m<j;m++){
	
	if(freq[m][str[i]-'0']>0)
	{
		cout<<"NO\n";
		return 0;
	}}
	freq[j][str[i]-'0']++;
	t=p[j];
}
}
cout<<"YES\n";
}
else
cout<<"NO\n";


}
