#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
ll prime[1000009],primesutil[1000009];
ll fac[1000009]; 
void pre()
{
     fac[0] = 1; 
    for (ll i=1 ; i<=1000000; i++) 
        fac[i] = fac[i-1]*i%mod; 
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;       
    x = x % p;  
    while (y > 0) 
    {  
        if (y & 1) 
            res = (res*x) % p; 
  
       
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
  

ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  

ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   
   if (r==0) 
      return 1; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
void sieve()
{
    prime[1]=1;
    for(int i=2;i*i<=1000000;i++)
    {
        if(prime[i] == 0)
        {
            for(int j=2*i;j<=1000000;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    pre();
    primesutil[1]=0;
    for(int i=2;i<=1000000;i++)
    {
        primesutil[i]+=primesutil[i-1];
        if(!prime[i])
            primesutil[i]+=1;
    }
    int t;
    cin>>t;
    while(t--)
    {
         ll n,k,x,ans=1;
         cin>>n>>k;
         x=primesutil[n]+1;
         
         if(x>=k)
         {
             ans = nCrModPFermat(x+k-1,k-1,mod);
         }
         else
         {
             ans = nCrModPFermat(2*x-1,x-1,mod);
             for(ll i=1;i<=x;i++)
             {
                 ans = ans * (k - i +1);
                 ans%=mod;
             }
             ans = ans * modInverse(fac[x],mod);
             ans%=mod;

         }
         cout<<ans<<"\n";
    }
}