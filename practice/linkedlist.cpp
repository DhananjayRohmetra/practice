#include<bits/stdc++.h>
using namespace std;
struct Node{
int val;
Node *next;
};

Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        Node* temp=new Node();
        temp->val=data;
        temp->next=NULL;
        root=temp;
        return root;
    }
    else
    {
        Node* temp=new Node();
        temp->val=data;
        temp->next=NULL;
        root->next=temp;
        root=temp;
        return root;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n,i;
    cin>>n;
    int arr[n+1];
    Node* root=NULL;
    Node * head=NULL;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            head=insert(root,arr[i]);
            root=head;
        }
        else
        {
            /* code */
            root=insert(root,arr[i]);
        }
    }
    root=head;
    while(root!=NULL)
    {
        cout<<root->val<<"\n";
        root=root->next;
    }
    
    
}
