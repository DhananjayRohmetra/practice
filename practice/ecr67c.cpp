#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n,m,flag=0;
    cin>>n>>m;
    int arr[n+2],brr[n+2];
    for(int i=1;i<=n;i++)
    {
        arr[i]=-1;
        brr[i]=-1;
    }
    int typ,l,r;
    vector<pair<int,int>>checker;
    for(int i=0;i<m;i++)
    {
        cin>>typ>>l>>r;
        if(typ == 1)
        {
            for(int x=l;x<=r-1;x++)
            {
               if(brr[x]==-1)
                {
                    brr[x]=0;
                }
            }
        }
        else
        {
            checker.push_back({l,r});
        }
        
    }
    arr[1]=n;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+brr[i-1];
    }
    for(int i=0;i<checker.size();i++)
    {
        int x=checker[i].first;
        int y=checker[i].second;
        int srt=0;
        for(int j=x;j<=y-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                srt++;
            }
        }
        if(srt == 0)
        {
            flag=1;
        }

    }
    if(flag == 1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    }
    

}