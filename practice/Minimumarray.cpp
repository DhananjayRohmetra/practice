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
#define all(v) v.begin(),v.end()

int main()
{
int n,x,i;
cin>>n;
multiset<int>mset;
int arr[n+1],c[n+1];
for(i=0;i<n;i++)
{
	cin>>arr[i];
}
    
for(i=0;i<n;i++)
{
	cin>>x;
	mset.insert(x);
}
multiset< int > :: iterator pos,pos1,pos2;
    
for(i=0;i<n;i++)
{
	
	pos1=mset.lower_bound(n-arr[i]);
        if(pos1!=mset.end())
        {
            c[i]=(arr[i]+*pos1)%n;
            mset.erase(pos1);
        }
        else
        {
            pos2=mset.lower_bound(0);
            if(pos2!=mset.end()){
            c[i]=(arr[i]+*pos2)%n;
                mset.erase(pos2);}
        }
        
		
	 
    cout<<c[i]<<" ";	
}
}


