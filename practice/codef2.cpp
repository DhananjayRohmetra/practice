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
int p[100009][19],l[100009],mm[100009];
vector< vector<int> >adj;
void dfs(int s,int par)
{
	for(auto  i:adj[s])
	{
		if(i!=par)
		{
			l[i]=1+l[s];
			dfs(i,s);
			p[i][0]=s;


		}
	}
}
int getlca(int pp,int qq)
{
	if(l[pp]<l[qq])
{
	swap(pp,qq);
}

int k,i;
for( k=1;(1<<k)<=l[pp];k++);
k--;

for(i=k;i>=0;i--)
{
	if(l[pp]-(1<<i)>=l[qq])
	{
		pp=p[pp][i];
	}
}

if(pp==qq) return pp;

for(i=k;i>=0;i--)
{
	if(p[pp][i]!=p[qq][i] && pp[p][i]!=-1)
	{
		pp=p[pp][i];
		qq=p[qq][i];
	}
}

return p[pp][0];
}
int main()
{
int k,flag=0,i;
cin>>k;
string s,s1,s2,s3,s4,s5;
for(i=5;i<=10000;i++)
{
	if(k%i==0)
	{
		if(k/i>=5 && i>=5)
		{
			flag=1;
		}
	}
}
if(flag==1)
{
		int ss=k/5;
	if(k%5!=0)
	{
	
	
	for(i=0;i<ss;i++)
	{
		s+="aeiou";
	}
	if(k-ss*5==1)
	{
		s+="a";
	}
	if(k-ss*5==2)
	{
		s+="ae";
	}
	if(k-ss*5==3)
	{
		s+="aei";
	}
	if(k-ss*5==4)
	{
		s+="aeio";
	}
	}
	else
	{
		s1="aeiou";
		s2="uaeio";
		s3="ouaei";
		s4="iouae";
		s5="eioua";
	int ss=k/25;
		for(i=0;i<ss;i++)
		{
			s+=s1+s2+s3+s4+s5;
		}
	if(k-ss*25==1)
	{
		s+="a";
	}
	if(k-ss*25==2)
	{
		s+="ae";
	}
	if(k-ss*25==3)
	{
		s+="aei";
	}
	if(k-ss*25==4)
	{
		s+="aeio";
	}
	if(k-ss*25==5)
	{
		s+=s1;
	}
	if(k-ss*25==6)
	{
	s+=s1+"u";
	}
	if(k-ss*25==7)
	{
		s+=s1+"ua";
	}
	if(k-ss*25==8)
	{
	s+=s1+"uae";
	}
	if(k-ss*25==9)
	{
		s+=s1+"uaei";
	}
	if(k-ss*25==10)
	{
	s+=s1+s2;
	}
	if(k-ss*25==11)
	{
		s+=s1+s2+"o";
	}
	if(k-ss*25==12)
	{
		s+=s1+s2+"ou";
	}
	if(k-ss*25==13)
	{
		s+=s1+s2+"oua";
	}
	if(k-ss*25==14)
	{
		s+=s1+s2+"ouae";
	}
	if(k-ss*25==15)
	{
	s+=s1+s2+s3;
	}
	if(k-ss*25==16)
	{
		s+=s1+s2+s3+"i";
	}
	if(k-ss*25==17)
	{
		s+=s1+s2+s3+"io";
	}
	if(k-ss*25==18)
	{
	s+=s1+s2+s3+"iou";
	}
	if(k-ss*25==19)
	{
	s+=s1+s2+s3+"ioua";
	}
	if(k-ss*25==20)
	{
		s+=s1+s2+s3+s4;
	}	
	if(k-ss*25==21)
	{
		s+=s1+s2+s3+s4+"e";
	}
	if(k-ss*25==22)
	{
		s+=s1+s2+s3+s4+"ei";
	}
	if(k-ss*25==23)
	{
		s+=s1+s2+s3+s4+"eio";
	}
	if(k-ss*25==24)
	{
		s+=s1+s2+s3+s4+"eiou";
	}
	}
cout<<s;
}
else
{
	cout<<"-1";
}
}


