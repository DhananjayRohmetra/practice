#include<bits/stdc++.h>
using namespace std;
long long int ar[200005],n,s=0;
void comb(long long int l,long long int r)
{
    long long int mid=(l+r)/2;
    long long int i,j,k;
    long long int br[200005],cr[200005];
    k=l;
    for(i=1;i<=mid-l+1;i++)
    {
        br[i]=ar[k];
        k++;
    }
    for(i=1;i<=(r-mid);i++)
    {
        cr[i]=ar[k];
        k++;
    }
    i=1;
    j=1;
    k=l;
    while(i<=(mid-l+1) && j<=(r-mid))
    {
        if(br[i]<=cr[j])
        {
            ar[k]=br[i];
            i++;
            s+=j-1;
        }
        else
        {
            ar[k]=cr[j];
            j++;
        }
        k++;
    }
    if(i>(mid-l+1))
    {
        for(i=j;i<=(r-mid);i++)
        {
            ar[k]=cr[i];
            k++;
        }
    }
    else
    {
        for(j=i;j<=(mid-l+1);j++)
        {
            ar[k]=br[j];
            k++;
            s+=(r-mid);
        }
    }
}
void merg(long long int l,long long int r)
{
    if(l==r)
        return;
    long long int mid=(l+r)/2;
    merg(l,mid);
    merg(mid+1,r);
    comb(l,r);
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int i;
        cin>>n;
        s=0;
        for(i=1;i<=n;i++)
        {
            cin>>ar[i];
        }
        merg(1,n);
        //for(i=1;i<=n;i++)
          //  cout<<ar[i]<<"\n";
        cout<<s<<"\n";
    }
}
