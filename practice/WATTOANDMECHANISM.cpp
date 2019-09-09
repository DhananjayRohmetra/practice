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
ll mod = 1110111110111;
ll base[1000008];
ll gethash(string str)
{
	ll len = str.size();
	ll hash = 0;
	for (ll i = 0; i < len; i++)
	{
		hash += base[i] * str[i];
		hash %= mod;
	}
	return hash;
}
int32_t main()
{
	ll n, i, j, q;
	cin >> n >> q;
	string str, str1;
	set<ll> set1;

	base[0] = 1;
	for (i = 1; i <= 1000001; i++)
	{
		base[i] = base[i - 1] * 11 % mod;
	}
	for (i = 0; i < n; i++)
	{
		cin >> str;
		set1.insert(gethash(str));
	}
	for (i = 0; i < q; i++)
	{
		ll flag = 0;
		cin >> str1;
		ll h = gethash(str1);
		ll len = str1.size();
		for (ll k = 0; k < len; k++)
		{
			for (j = 'a'; j < 'd'; j++)
			{
				if (str1[k] != j)
				{
					;
					if (set1.find((((j - str1[k]) * base[k] + h) + 4 * mod) % mod) != set1.end() && flag == 0)
					{
						cout << "YES\n";
						flag = 1;
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "NO\n";
		}
	}
}

/*
1 1
acbacbacb
acbacbac
*/
