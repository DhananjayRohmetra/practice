#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
ll main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    ll arr[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll num[n + 1][12];
    memset(num, 0, sizeof(num));
    ll dig[n + 1];
    memset(dig, 0, sizeof(dig));
    for (ll i = 0; i < n; i++)
    {
        ll nums = arr[i];
        ll res = 0;
        while (nums != 0)
        {
            num[i][res] = nums % 10;
            nums = nums / 10;
            res++;
        }
        dig[i] = res;
    }
    ll freqnum[12], sum = 0;
    ll z[12];
    memset(z, 0, sizeof(z));
    memset(freqnum, 0, sizeof(freqnum));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= dig[i]; j++)
        {
            freqnum[j]++;
        }
        z[dig[i]]++;
    }

    for (ll i = 0; i < n; i++)
    {
        ll ress = 1;
        for (ll j = 0; j < 10; j++)
        {

            if (j == 0)
            {
                sum = (sum + freqnum[j + 1] * num[i][j] * (ress + ress * 10) + mod) % mod;
                sum = (sum + mod) % mod;
                ress = ((ress * 10) % mod * 10) % mod;
            }
            else
            {

                if (num[i][j] != 0)
                {
                    for (ll x = 1; x <= j + 1; x++)
                    {
                        ll rest;
                        if (x <= j)
                        {
                            rest = (2 * num[i][j] * z[x] * power(10, x + j, mod) + mod) % mod;
                            sum = sum + rest;
                            sum = (sum + mod) % mod;
                        }
                        else
                        {
                            sum = (sum + freqnum[j + 1] * num[i][j] * ((power(10, 2 * j, mod) + power(10, 2 * j + 1, mod) + mod) % mod) + mod) % mod;
                            sum = (sum + mod) % mod;
                            //ress=((ress*10)%mod*10)%mod;
                        }

                        //cout<<rest<<"\n";
                    }
                }
            }
        }
    }
    cout << (sum + mod) % mod;
}