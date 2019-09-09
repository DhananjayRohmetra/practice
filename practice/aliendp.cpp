#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll n,k,x,l,r,t,i,s,count=0,p;
	vector<pair< ll,ll > >vec,vec1;
	cin>>n>>k;
	ll arr[n+2],brr[n+2],crr[n+2];
	
	for(i=1;i<=n;i++)
	arr[i]=0;
	
	
	while(k--)
	{
	cin>>l>>r>>x;
	t=x/(r-l+1);
	if(r == n )
	{
		arr[l]+=t;
	}
	else
	{
	arr[l]+=t;
	arr[r+1]=-t;	
	}	
	}
	for(i=2;i<=n;i++)
	{
		arr[i]+=arr[i-1];
	}
	for(i=0;i<n;i++)
	{
		crr[i]=arr[i+1];
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		vec.push_back(make_pair(s-crr[i],i));
	}
	sort(vec.begin(),vec.end());
for(i=0;i<n;i++)
{
if(vec[i].first>0)
{
	p=i;
	break;
}
}
i=p;
count=0;
 ll a[n][3],j=0;
    if(p>0){
/*while(count<=p-1)
{
if(abs(vec[count].first)>vec[i].first)
{
     
	a[j][0]=vec[count].second+1;
	a[j][1]=vec[i].second+1;
	a[j][2]=vec[i].first;
         j++;
	//cout<<vec[count].second+1<<" "<<vec[i].second+1<<" "<<vec[i].first<<"\n";
	vec[count].first+=(vec[i].first);
	i++;
}	
else if(abs(vec[count].first)==vec[i].first)
{
    
	a[j][0]=vec[count].second+1;
a[j][1]=vec[i].second+1;
a[j][2]=vec[i].first;
        j++;
//	cout<<vec[count].second+1<<" "<<vec[i].second+1<<" "<<vec[i].first<<"\n";
	vec[count].first+=(vec[i].first);
	i++;
	count++;
}
else if(abs(vec[count].first)<vec[i].first)
{
   
	a[j][0]=vec[count].second+1;
a[j][1]=vec[i].second+1;
a[j][2]=abs(vec[count].first);
         j++;
//	cout<<vec[count].second+1<<" "<<vec[i].second+1<<" "<<abs(vec[count].first)<<"\n";
	vec[count].first=0;
	count++;
}
    else
    {
        i++;}
}*/
}
cout<<j<<endl;
for(i=0;i<j;i++)
{
	cout << a[i][0] << " " << a[i][1] <<" " << a[i][2] << endl; 
}
}
