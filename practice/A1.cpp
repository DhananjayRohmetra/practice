#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long x=n;
    long long s=0;
    while(x!=0)
    {
        ++s;
        x/=10;
    }
    long long z=1;
    for(long long i = 0; i<s ; i++)
        z=z*10;
    long long y=s*z-((z-1)/9);
    cout<<y<<"\n";

}
