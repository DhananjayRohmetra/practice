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

ll n,arr[100002],aee[5];
vector<ll>tree[500002];
ll func(ll a,ll s1) {
	return 4*a*a*s1*s1-s1*s1*s1*s1;
}
void build(ll node,ll start,ll end) {
	if(start==end) {
		tree[node].pb(arr[start]);
		return;
	}
	ll mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node]));
}

ll query(ll node,ll start,ll end,ll l,ll r,ll a) {
	if(start==end) {
		return tree[node][0];
	}
	if(start>end || start>r || end<l) return 0;
	if(start>=l && end<=r) {
		ll r=upper_bound(all(tree[node]),a)-tree[node].begin();
		return arr[r];
	}
	ll mid=(start+end)/2;
	return max(query(2*node,start,mid,l,r,a),query(2*node+1,mid+1,end,l,r,a));

}
ll query1(ll node,ll start,ll end,ll l,ll r,ll a) {
	if(start==end) {
		return tree[node][0];
	}
	if(start>end || start>r || end<l) return 1e14;
	if(start>=l && end<=r) {
		ll r=lower_bound(all(tree[node]),a)-tree[node].begin()+1;
		return arr[r];
	}
	ll mid=(start+end)/2;
	return min(query(2*node,start,mid,l,r,a),query(2*node+1,mid+1,end,l,r,a));

}

int main() {
	ll i,t,c,l,r,s1,s2,s3,s4,ans;
	double a,b;
	cin>>n>>t;
	for(i=1; i<=n; i++) {
		cin>>arr[i];
	}
	build(1,1,n);
	while(t--) {
		cin>>l>>r>>a;
		b=sqrt(2)*a*1.0;
		c=floor(b);
		s1=query(1,1,n,l,r,c);
		s3=query1(1,1,n,l,r,c);

		c=ceil(b);
		s2=query1(1,1,n,l,r,c);
		s4=query(1,1,n,l,r,c);
		aee[0]=func(a,s1);
		aee[1]=func(a,s2);
		aee[2]=func(a,s3);
		aee[3]=func(a,s4);
		ll maxx=-1;
		for(i=0; i<4; i++) {
			if(aee[i]>maxx) {
				maxx=aee[i];
			}
		}
		for(i=0; i<4; i++) {
			if(aee[i]==maxx) {
				ans=i;
				break;
			}
		}
		if(i==0) {
			cout<<s1<<endl;
		}
		if(i==1) {
			cout<<s2<<endl;
		}
		if(i==2) {
			cout<<s3<<endl;
		}
		if(i==3) {
			cout<<s4<<endl;
		}
	}

}

