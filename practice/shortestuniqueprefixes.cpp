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
int n;
struct node{
int free=0;
node *ar[26];
	node()
	{
		free=0;
		for(int i=0;i<26;i++)
		{
			ar[i]=NULL;
		}
	}
};
void add(struct node *root,string s,int idx)
{
	if(idx==s.length()) return;
	if(root->ar[s[idx]-'a']==NULL)
	{
		root->ar[s[idx]-'a']=new node();
	}
	root->ar[s[idx]-'a']->free++;
	add(root->ar[s[idx]-'a'],s,idx+1);
}
int find(struct node *root,string s,int idx)
{
	if(root->ar[s[idx]-'a']->free==1)
	return idx;
	if(root->ar[s[idx]-'a']!=NULL){
	return find(root->ar[s[idx]-'a'],s,idx+1);
	}
return -1;	
}
void dfs(struct node *root)
{
	
	for(int i=0;i<26;i++)
	{
		if(root->ar[i]!=NULL)
		{
		  if(root->ar[i]->free==n){
		  	cout<<char(97+i); //LCP
		  }
			dfs(root->ar[i]);
		}
	}
}
int main()
{
	int i,indexx,j;
	cin>>n;
	string str;
	vector<string>vec;
	for(i=0;i<n;i++)
	{
		cin>>str;
		vec.pb(str);
	}
	struct node *root=new node();
	for(i=0;i<n;i++)
	{
		add(root,vec[i],0);
	}
	dfs(root);
	for(i=0;i<n;i++)
	{
		indexx=find(root,vec[i],0);
		//cout<<indexx;
		for(j=0;j<=indexx;j++)
		{
		//	cout<<vec[i][j];
		}
		//cout<<"\n";
	}
}



