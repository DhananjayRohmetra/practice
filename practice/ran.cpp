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
	node *left;
	node *right;
};
struct node newnode(int key)
{
	 struct node *temp =  (struct node *)malloc(sizeof(struct node));
	 temp->right=NULL;
	 temp->left=NULL;
	 temp->data=key;
	 return *temp;
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
struct node* insert(node *root,int val)
{
	if(root==NULL)
	{
		struct node *root =  (struct node *)malloc(sizeof(struct node));
		root->right=NULL;
	 	root->left=NULL;
		root->data=val;
	}
	else
	{
		if(val>=root->data)
		{
			root->right=insert(root->right,val);
		}
		else
		{
			root->left=insert(root->left,val);
		}
	}
	return root;
}
int main()
{

	struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root); 
   
}



