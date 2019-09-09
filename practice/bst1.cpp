#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MAX5 100010
struct node{
	int val;
	node *left,*right;
};
node *newNode(int data)
{
	struct node *temp=(node*)malloc(sizeof(struct node));
	temp->val=data;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node * root,int data)
{
	if(root==NULL)
		return newNode(data);
	else
	{
		if(root->val>data)
			root->left=insert(root->left,data);
		else
			root->right=insert(root->right,data);
		return root;
	}
}
node *search(node *root,int key)
{
	if(root==NULL || root->val==key)
		return root;
	else
	{
		if(root->val>key)
			return search(root->left,key);
		else
			return search(root->right,key);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<'\n';
		inorder(root->right);
	}
}
int main()
{
	struct node *root=NULL;
	root=insert(root,10);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,12);
	root=insert(root,15);
	root=insert(root,5);
	inorder(root);
}
