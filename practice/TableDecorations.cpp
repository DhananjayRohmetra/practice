#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    ll arr[4],ans=0,resa;
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    ll first = (arr[2] + 2)/3;
    if(arr[1] + arr[0] <= first )
    {
        ans=arr[1]+arr[0];
    }
    else
    {
        arr[0]-=first/2;
        arr[1]-=first/2;
        if(first%2 != 0)
        { 
            arr[1]-=1;
        }
        resa = arr[2] - 2*first;
        
    }
    
}
    