#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,z1,z2;
long long int ar[5003],br[5003],visit[5003][5003],dp[5003][5003];
long long int rec(long long int i,long long int j)
{
    cout<<i<<" "<<j<<"\n";
    if(i+j==n)
    return 0;
    //if(i==a || j==b)
    //return 0;
    if(visit[i][j]!=0)
    {
        return dp[i][j];
    }
    if(i<a)
    z1=ar[i+j+1]+rec(i+1,j);
    else
    z1=0;
    if(j<a)
    z2=br[i+j+1]+rec(i,j+1);
    else
    z2=0;
    visit[i][j]=1;
    return dp[i][j]=max(z1,z2);
}
int main()
{
    long long int i;
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>br[i];
    }
    cout<<rec(0,0);
}
