#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 9223372036854775807 ;
ll n,a,b;
char arr[200007];
ll dp[200007][3];
ll recur(int idx,int h)
{
    //cout<< idx << " " <<h<<"\n";
 
    if(idx==n)
    {
        if(arr[idx-1]=='1' && h==0)
            return maxn;
        if(h==1)
            return 3*b+2*a;
        else
            return 2*b+a; 
    }
   
    if(dp[idx][h]!=maxn)
        return dp[idx][h];
        
    
    if(arr[idx-1]=='0')
    {
        if(h==0)
            dp[idx][h]=min(a+recur(idx+1,h),2*a+recur(idx+1,1))+b;
        if(h==1)
            dp[idx][h]=min(a+recur(idx+1,h),2*a+recur(idx+1,0))+2*b;
    }
    if(arr[idx-1]=='1')
    {
        if(h==0)
           return maxn; 
        if(h==1)
            dp[idx][h]=min(a+recur(idx+1,1),2*a+b+recur(idx+1,0))+2*b;
    }
   return dp[idx][h];
    
    
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        
        //cout<<n<<"\n";
        for(int i=0;i<n;i++)
        cin>>arr[i];
       
       for(int i=0;i<=n;i++)
        {
            for(int j=0;j<2;j++)
            {
              dp[i][j]=maxn;
            }
        }
         recur(1,0) ;
        cout<<min(dp[1][0],dp[1][1])<<"\n";
         for(int i=0;i<=n;i++)
        {
         // cout<<i<<" ";
            for(int j=0;j<2;j++)
            {
           //   cout << dp[i][j] <<" ";
            }
          // cout<<"\n";
        }
    }
}