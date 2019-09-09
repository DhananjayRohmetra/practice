#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *up;
};
struct node *root1=NULL;
int max1=0;
int maxheight(struct node *root,int h)
{
    if(root==NULL)
        return;
    max1=max(max1,h);
    maxheight(root->left,h+1);
    maxheight(root->right,h+1);
}
void rec(struct node *root,struct node *nptr)
{
    if(root->data>nptr->data)
    {
        if(root->left==NULL)
        {
            root->left=nptr;
            nptr->up=root;
            return;
        }
        rec(root->left,nptr);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=nptr;
            return;
        }
        rec(root->right,nptr);
    }
}
void pre(struct node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
int main()
{
    while(1)
    {
        int val;
        cin>>val;
        struct node *nptr=(struct node*)malloc(sizeof(struct node));
        nptr->data=val;
        nptr->left=NULL;
        nptr->right=NULL;
        node->up=nptr;
        if(root1==NULL)
        {
            root1=nptr;
        }
        else
        {
            rec(root1,nptr);
            if(abs(maxheight(root1->left)-maxheight(root1->right)>1)
               {
                   rot(root1,nptr);
               }
        }
        pre(root1);
    }
}
