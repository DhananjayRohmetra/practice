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
      int data;     // data stored in node. here data is of int type
      node *left;   // pointer to left node of current node
      node *right;  // pointer to right node of current node
};
struct node* insert(node* root ,int val)
{
	if(root == NULL)
	{
		node *N=new node();
		N->data = val;
        N->left = N->right = NULL;
        root=N;
	}
	else if(root->data >= val)
	{
		root->left=insert(root->left,val);
	}	
	else
	{
		root->right=insert(root->right,val);
	}
	return root;
}
int traversal(struct node* root)
{
	if(root!=NULL)
	{
		int leftheight=traversal(root->left);
		int rightheight=traversal(root->right);
		return 1+max(leftheight,rightheight);
	}
	else if(root== NULL)
	{
		return 0;
	}
}
int main()
{
	
   	int n;
   	cin>>n;
   	int arr[n+2];
   	for(int i=0;i<n;i++)
   	cin>>arr[i];
   	struct node *root = NULL; 
	for(int i=0;i<n;i++)
	{
		root=insert(root,arr[i]);
	}
	cout<<traversal(root);
	
	
}



