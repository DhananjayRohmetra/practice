#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,l,r,i,j=1;
	    cin>>n>>l>>r;
        ll arr[n+2],freq[100002],value[100002],freq1[100002],index1,pref[100002],index2,index3,index4,plower,phigher,s=0;
    for(i=1;i<=100000;i++)
     {
     freq[i]=0;
     }
	 for(i=1;i<=n;i++)
     {
     cin>>arr[i];
         s+=arr[i];
     freq[arr[i]]++;
     }
     sort(arr,arr+n);
     	 pref[0]=0;
	 for(i=1;i<=100000;i++)
     {
     	if(freq[i]!=0)
     	{
     		value[j]=i;
     		freq1[j]=freq[i];
            pref[j]=i*freq[i];
     		j++;    	
		}
	 }
for(i=1;i<j;i++)
{
	pref[i]+=pref[i-1];
}
	for(i=1;i<j;i++)
	{
	
		index1=lower_bound(value,value+j,value[i]-l)-value;
        index2=upper_bound(value,value+j,value[i]-l)-value;
		index3=lower_bound(value,value+j,value[i]+r)-value;
        index4=upper_bound(value,value+j,value[i]+r)-value;
		//cout<<index1<<" "<<index2<<endl;
        if(freq[value[i]+r]>0)
        {
        	phigher=index3;
		}
		if(freq[value[i]+r]==0)
		{
				phigher=index3-1;
		}
		 if(freq[value[i]-l]>0)
        {
        	plower=index1-1;
		}
		if(freq[value[i]-l]==0)
		{
				plower=index1-1;
		}
        if(plower==-1)
        {
        plower=0;}
		//cout<<plower<<" "<<phigher<<endl;
        cout<<s-(pref[phigher]-pref[plower]-(freq[value[i]])*value[i])<<endl;
	}
	}
}
