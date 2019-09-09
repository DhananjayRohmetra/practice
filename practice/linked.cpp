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
struct node{
	int data;
	node *next;
};
int main()
{
	int n;
	cin>>n;
	struct node *head=NULL;
   	struct node *tail=NULL;
   		
	for(int i=0;i<n;i++)
	{
		int x;
   		cin>>x;
   			node *N=new node();
			N->data=x;
			N->next=NULL;
   		if(head == NULL)
   		{
   			head=N;
			tail=head;
		}
		else
		{
			tail->next=N;
			tail=N;	
		}
	}
	int y,zz;
	cin>>y>>zz;
	int cnt=0;
	struct node *x=NULL;
	struct node *z=NULL;
	struct node *start=NULL;
	x=head;
	z=head;
	start=head;
	if(zz==0)
	{
		
		node *N=new node();
			N->data=y;
			N->next=head;
			head=N;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	
	}
	if(zz>0 && zz<=n-1)
	{
	while(head!=NULL)
	{
		
		if(cnt==zz)
		{
		node *N=new node();
			N->data=y;
			z->next=N;
			N->next=head;
			head=N;	
		}
		cout<<head->data<<" ";
		z=head;
		head=head->next;	
		cnt++;
	}
	}
	if(zz==n)
	{
	while(head!=NULL)
	{
		//cout<<head->data<<" ";
		z=head;
		head=head->next;	
	}
		node *N=new node();
		N->data=y;
		N->next=NULL;
		z->next=N;
	while(start!=NULL)
	{
		cout<<start->data<<" ";
		z=head;
		start=start->next;	
	}
	}
}



