#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()
int main()
{
		vector<int>nums1{-48,-46,-46,-46,-45,-45,-44,-42,-38,-36,-35,-34,-33,-32,-32,-32,-30,-29,-28,-28,-26,-25,-23,-19,-15,-13,-12,-10,-8,-7,-6,-4,-2,0,0,0,1,1,2,4,4,5,6,8,11,11,16,16,22,23,23,24,25,25,26,28,29,30,32,33,34,34,35,35,36,36,38,40,41,42,42,42,42,45,48,0,0,0,0,0,0,0};
		vector<int>nums2{-36,-27,-24,-14,-13,2,9};
        int m=75,n=7;
		vector<int>ans;
        
        int i=0,j=0,k,x=m+n;
        while(m!=i && n!=j)
        {
        	if(nums1[i]>nums2[j])
        	{
        		ans.pb(nums2[j]);
        		j++;
			}
			else
			{
				ans.pb(nums1[i]);
				i++;
			}
		}
		if(m==i)
		{
			for(k=j;k<n;k++)
			{
				ans.pb(nums2[k]);
			}
		}
		if(n==j)
		{
			for(k=i;k<m;k++)
			{
				ans.pb(nums1[k]);
			}
		}
		nums1.clear();
		for(i=0;i<x;i++) 
		nums1.pb(ans[i]);
		for(i=0;i<x;i++) 
		cout<<ans[i];
		
    }

