#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n,sum;
    cin>>n>>sum;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);
    int st=0;
    int en=n-1;
    while(st<=en)
    {
        if(arr[st]+arr[en]<sum)
        {
            st++;
        }
        else
        {
            if(arr[st]+arr[en]==sum)
            {
                cout<<arr[st]<<" "<<arr[en]<<"\n";
            }
            en--;
        }
    }
}