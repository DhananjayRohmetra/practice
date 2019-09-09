#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	  multiset <ll, greater <ll> > gquiz1; 
	  multiset< ll, greater <ll> > :: iterator it;    
	  vector< pair <ll,ll> > vec;      
	ll n,q,k,end,h,var=0,j=0,i,start;
	char ans;
	cin>>n>>q>>k;
	ll arr[n+4];
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<=n;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			vec[j].first = i-var;
			vec[j].second = arr[i];
			var=i;
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		if(vec[i].second==1)
		{
		 gquiz1.insert(vec[i].first);
		}
	}
	end=j-1;
	start=0;
for(h=1;h<=q;h++)
{
	cin>>ans;
	if(ans=='?')
	{
		cout<<min(k,*(gquiz1.begin()))<<"\n";
	}
	else
	{
	if( vec[vec.size()-1].second == vec[start].second  )
	{
		if(vec[vec.size()-1].second == 1 &&  vec[start].second==1)
		{
		
		 gquiz1.erase(*(gquiz1.find(vec[start].first)));
		 gquiz1.insert(vec[start].first+1);
		 vect[start].first++;
	 	 gquiz1.erase(*(gquiz1.find(vec[vec.size()-1].first)));
		  
     if(vec[vec.size()-1].first!=1)
     {

     	gquiz1.insert(vec[vec.size()-1].first-1);
     	vec.end().first--;
     	
	 }
	 else
	 {
	 	vec.erase(vec.begin()+vec.size()-1);
	 }
}
else if(vec[vec.size()-1].second == 0 &&  vec[start].second==0)
{
		 vect[start].first++;
    if(vec[vec.size()-1].first!=1)
     {
     	vec[vec.size()-1].first--;	
	 }
	 else
	 {
	 	vec.erase(vec.begin() + vec.size());
	 }
}
	
	}
else 
{
	if(vec[start].second==0 && vec[vec.size()-1].second==1)
	{
		  auto it = vec.insert(vec.begin(), make_pair(1,1)); 
		
		       if(vec[vec.size()-1].first!=1)
     {

     	gquiz1.insert(vec[vec.size()-1].first-1);
     	vec.end().first--;
     	
	 }
	}
}
	}
}
	
}
