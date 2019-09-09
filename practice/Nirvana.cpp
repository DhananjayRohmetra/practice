#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
int main()
{
int  n,i=0,j,ans=-1,arr[11],p=1;
cin>>n;
memset(arr, 0 ,sizeof(arr));
while(n!=0)
{
	arr[i]=n%10;
	p=p*arr[i];
	n=n/10;
	i++;


}
//cout<<p;

int pp=1;
for(j=0;j<i/2;j++)
{
	swap(arr[j],arr[i-j-1]);
}
cout<<arr[0]<<arr[1];

	if(arr[0]>1 && arr[1]>1)
	{
		for(int ii=0;ii<i;ii++)
		{
			if(arr[i]>1)
			{
			int	x=p*(arr[i]-1)*pow(9,i-j-1);
			cout<<x<<"\n";
			if(ans<x)
			{
				ans=x;
			}
			pp*=arr[i];
			}
			else
			{
				break;
			}
			
		}
	}
	
	if(arr[0]>1 && arr[1]<=1)
	{
		int	x=(arr[0]-1)*pow(9,i-1);
	if(ans<x)
	{
		ans=x;
	}
	}
	else
	{
	int	x=pow(9,i-1);
	if(ans<x)
	{
		ans=x;
	}
		//	ans=max(ans,pow(9,i-1));
	}

//	cout<<max(p,ans);


	return 0;
}

