#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long 
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vector<pair<ll, ll>> vec;
int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll arr[n + 1], pref[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    memset(pref, 0, sizeof(pref));
    pref[0] = arr[0];
    for (ll i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];
       ll ans=0;
       ordered_set me;
       ll t=0,s;
    for (ll i = 0; i < n; i++)
    { 
    	if( i == 0 && pref[i]<k)
    	{
    			ans++;
    			me.insert({pref[i], t++});
    	}
    	else
    	{
    	if( pref[i]<k)
    	{
    			ans++;
    			
    	}
          s=me.order_of_key({pref[i]-k+1, 0});
          ans+=i-s;
          me.insert({pref[i], t++});
    	}
    }
    cout << ans;
}