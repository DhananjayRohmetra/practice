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
struct Node{
	int data;
	Node* next; 
};

void FrontBackSplit(Node** source, 
					Node** frontRef, Node** backRef); 
Node* SortedMerge(Node* a,Node* b)
{
	Node* result = NULL; 
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 
	if (a->data <= b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return (result); 
} 
void Merge(Node** head_ref)
{


	Node* head=*head_ref;
	Node* a;
	Node* b;
	if ((head == NULL) || (head->next == NULL)) { 
	return; 
	} 
	FrontBackSplit(&head,&a,&b);
	Merge(&a);
	Merge(&b);
	*head_ref = SortedMerge(a, b);
}


void FrontBackSplit(Node** source,Node** frontRef,Node** backRef)
{
	Node* fast; 
	Node* slow;
	slow=*source;
	fast=(*source)->next;
	while(fast!=NULL)
	{
	fast=fast->next;
	if(fast!=NULL)
	{
	fast=fast->next;
	slow=slow->next;	
	}	
	}
	*frontRef=*source;
	*backRef=slow->next; 
	slow->next=NULL;
}
void push(Node** head_ref,int data)
{
	Node *newNode=new Node();
	newNode->data=data;
	newNode->next=*head_ref;
	*head_ref=newNode;
}
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 
int main()
{
	Node* res = NULL; 
	Node* a = NULL; 
	push(&a, 15); 
	push(&a, 10); 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 3); 
	push(&a, 2); 
	Merge(&a);
	cout << "Sorted Linked List is: \n"; 
	printList(a); 
}



