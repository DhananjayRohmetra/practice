#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
#include <set>
#include <stack>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>
#include <sstream>
#include <climits>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define pb push_back
#define Check cout<<"CHECK"<<endl;
#define ed end()
#define bg begin()
#define sz size()
#define endl "\n"
#define pf(x) cout<<x<<endl;
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace boost::multiprecision;
 
using namespace std;
  
ll power(ll x, unsigned ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
// Returns nCr % p.  In this Lucas Theorem based program, 
// this function is only called for n < p and r < p. 
ll mod=1000000007;
ll nCrModpDP(ll n, ll r, ll p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (ll i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (ll j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
  
// Lucas Theorem based function that returns nCr % p 
// This function works like decimal to binary conversion 
// recursive function.  First we compute last digits of 
// n and r in base p, then recur for remaining digits 
ll nCrModpLucas(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
   // Compute last digits of n and r in base p 
   ll ni = n%p, ri = r%p; 
  
   // Compute result for last digits computed above, and 
   // for remaining digits.  Multiply the two results and 
   // compute the result of multiplication in modulo p. 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 
  
int32_t main()
{
	ll t;
	cin>>t;
	while(t--)
	{
  	ll n,i,j,ans=0;
   	cin>>n;
   	ll num[n+1];
   	memset(num,0,sizeof(num));
   	i=1;
	while(n/i>=4)
	{
		i++;
	}
	i--;
	for(j=1;j<=i;j++)
	{
	num[j]=	nCrModpLucas(n/j,4,mod);
	}
	for(j=n;j>=1;j--)
	{
		ll temp=0;
		if(num[j]==0)
		continue;
		else
		{
		for(i=2*j;i<=n;i+=j)
		{
			temp+=num[i];
		}
		num[j]-=temp;
		}
		
	//	cout<<num[j]<<"\n";
	}
	cpp_int res=0;
        for(int i=1;i<=n;i++){
            res+=(num[i]*power(i, 4,mod));
        }
        cout<<res%mod<<endl;
	}
}
 
