#include<bits/stdc++.h>
using namespace std;
long long int n,a,b;
long long int ar[5003],br[5003],visit[5003][5003],dp[5003][5003];
long long int rec(long long int i,long long int j)
{
    if(i+j==n)
    return 0;
    if(visit[i][j]!=0)
    {
        return dp[i][j];
    }

    if(i==a)
    {
        visit[i][j]=1;
        return dp[i][j]=br[i+j+1]+rec(i,j+1);
    }

    if(j==b)
    {
        visit[i][j]=1;
        return dp[i][j]=ar[i+j+1]+rec(i+1,j);
    }


    long long int z1=ar[i+j+1]+rec(i+1,j);
    long long int z2=br[i+j+1]+rec(i,j+1);
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
