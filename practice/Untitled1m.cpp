#include<bits/stdc++.h>
using namespace std;
#define ll long long

int recur(int t,int k);
int dp[10009][100];
int main()
{
	  memset(dp, 0, sizeof(dp[0][0]) * 10009 * 100);
 for(int k=1;k<=2;k++){
     
		recur(9,k);}
       
    int test;
    cin>>test;
    while(test--)
    {
    int x,k1;
        cin>>x>>k1;
        cout<<dp[x][k1];
    }
}
int recur(int t,int k)
{
	
    if(t<0)
    return 0;
    if(t==0)
    return 1;
    if(dp[t][k]!=0)
    return dp[t][k];
    else
    {
        for(int i=1;i<=k;i++)
        {
        
            dp[t][k]+=recur(t-i,k);
             
        }
        return dp[t][k];
    }
}
