#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n,ans=0;
        cin>>n;
        for(int x=n-2;x>=n/3+1;x--)
        {
            int res=n-x;
            if(res <= x)
            {
                ans=ans+(res/2)*6;
                if(res%2 == 0)
                {
                    ans-=3;
                }
            }
            else
            {
                ans+=6*(res/2-(res-x));
                if(res%2 == 0)
                {
                    ans-=3;
                }
            }
            
        }
        if(n<5)
        {
            cout<<"0\n";
        }
        if(n == 5)
        {
            cout<<"3\n";
        }
        if(n>5)
        {
            cout<<ans<<"\n";
        }
    }
}