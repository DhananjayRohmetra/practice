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
ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
} 
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,mod=15000000000031;
long long rev[1000002];
rev[1]=1;
for(int i=2;i<1000002;i++)rev[i]=mod-(mod/i)*rev[mod%i]%mod;
    cin>>n>>m;
    ll xx=mulmod(n,n+1,mod);
    ll yy=mulmod(m,m+1,mod);
    ll ans=mulmod((xx-yy+mod)%mod,(rev[2]%mod),mod);
    printf("%lld",ans);    
}

