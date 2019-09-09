#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,d,flag=0;
    cin>>n;
    ll arr[n+9],k=0,crr[n+9];
    vector<ll>vec;
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    sort(arr,arr+n);
    d=arr[1]-arr[0];
    for(i=2;i*i<=d;i++)
    {
        if(d%i==0)
        {
        	if(d/i==i)
        	{
        		vec.push_back(i);
			}
			else
			{
				vec.push_back(i);
				vec.push_back(d/i);
			}
		}
    }
 
    for(j=0;j<vec.size();j++)
    {
        flag=0;
        for(i=0;i<n-1;i++)
        {
            if((arr[i]%vec[j])!=(arr[i+1]%vec[j]))
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<crr[j]<<" ";
        }
    }
}


