#include<bits/stdc++.h>
using namespace std;
int dp[7][100004];
int main()
{


for(int i=1;i<=5;i++ )
{
for(int j=1;j<=100001;j++)
{
if(i>j){
dp[i][j]=dp[i-1][j]+dp[i][j-i];}
else
{
dp[i][j]=dp[i-1][j];

}

}

}

cout<<dp[5][100001];



}
