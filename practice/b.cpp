#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    //freopen("input.txt", "r", stdin);
    ll t;
    cin>>t;
    while(t--)
    {
        ll  c,x,ans=0;
        cin>>c>>x;
        ll p=1,pp=0;
        if( x > 1)
        {
	        while(pp < c)
	        {
	        	p=1;
	            for(int i=0;i<=32;i++)
	            {
	                p=p*x;
	                if(c - pp < p*x)
	                {
	                    break;
	                }
	            }
	            ans++;
	            pp +=p;
	            if(c - pp < x)
	            break;
	        }
        ans = ans+(c - pp);
        }
        if( x == 1)
        {
            ans = c;
        }
        if(x > c)
        {
            ans = c;
        }
        cout<<ans<<"\n";
    }
}