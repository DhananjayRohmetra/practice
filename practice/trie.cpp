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

struct trienode{
		struct trienode *child[26];
		bool isend;
		int word;
		int prefix;	
	};
	
	struct trienode *getnode(void)
	{
		struct trienode *pnode=new trienode;
		pnode->isend=false;
		for(int i=0;i<26;i++)
		{
			pnode->child[i]=NULL;
		}
		return pnode;
	}
void insert(struct trienode *root , string key)
{
	struct trienode *pcrawl=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!pcrawl->child[index])
		{
			pcrawl->child[index]=getnode();
		}
		pcrawl=pcrawl->child[index];
	}
	pcrawl->isend=true;
}

bool search(struct trienode *root , string key)
{
	struct trienode *pcrawl=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!pcrawl->child[index])
		{
			return false;
		}
		pcrawl=pcrawl->child[index];
	}
	return true;
}
int main()
{
	string keys[]={"the","a","there","answer","any","by","bye","their"};
	struct trienode *root=getnode();
	for(int i=0;i<8;i++)
	{ 
		insert(root,keys[i]);
	}
	
	search(root,"the")?cout<<"Yes\n":cout<<"No\n";
	search(root,"an")?cout<<"Yes\n":cout<<"No\n";
	
}

