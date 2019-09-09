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
ll len;
ll arr[100003];
ll freq[100003];
ll  n,r = 0;
struct Query 
{ 
    ll L, R, id; 
}; 
bool compare(Query x, Query y) 
{ 
    // Different blocks, sort by block. 
    if (x.L/len != y.L/len) 
        return x.L/len < y.L/len; 
  
    // Same block, sort by R value 
    return x.R < y.R; 
} 
void add(ll a,ll v)
{
	if(arr[a]<=n)
	{
	if(freq[arr[a]]==arr[a]) 
	{r--;}
	freq[arr[a]]+=v;
	if(freq[arr[a]]==arr[a]) 
	{r++;}
	}
}
int main()
{
	ll i,j,y;
	cin>>n>>y;
	memset(arr,0,sizeof(arr));
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	len=sqrt(n);
	Query q[y+2];
	ll answerr[y+2];
	for(i=0;i<y;i++)
	{
		cin>>q[i].L>>q[i].R;
		q[i].L--;
		q[i].R--;
		q[i].id=i;
	}

	memset(freq,0,sizeof(freq));
	sort(q, q + y, compare);
	ll currL = 0, currR = -1; 
	
	for(i=0;i<y;i++)
	{
	ll L=q[i].L;
	ll R=q[i].R;
	while(currL<L)
	{add(currL++,-1);}
	while(currL>L)
	{add(--currL,1);}
	while(currR<R)
	{add(++currR,1);}
	while(currR>R)
	{add(currR--,-1);}
	answerr[q[i].id]=r;
	//cout<<q[i].L<<" "<<q[i].R<<" "<<currSum<<"\n";
	} 
	for(i=0;i<y;i++)
	{
		cout<<answerr[i]<<"\n";
	}
}



