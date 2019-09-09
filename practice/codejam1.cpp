#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll k=1;k<=t;k++)
    {
        char ar[105],first[105],second[105]
        cin>>ar;
        ll h=strlen(ar);
        ll pos=-1,l=0,flag=0;
        for(ll i=0;i<h;i++)
        {
            if(ar[i]=='4')
            {
                first[i]='2';
                second[i]='2';
            }
            else
            {
                first[i]=ar[i];
                second[i]='0';
            }
        }
        for(ll p=0;p<h;p++)
        {
            if(second[p]!='0')
            {
                pos=p;
                break;
            }
        }
        printf("Case #%lld: ",k);

        for(ll i=0;i<h;i++)
        {
            printf("%c",first[i]);
        }
        printf(" ");
        if(pos!=-1)
        {
            for(ll i=pos;i<h;i++)
            {
                printf("%c",second[i]);
            }
        }
        else
            printf("0");

        printf("\n");
    }
}
