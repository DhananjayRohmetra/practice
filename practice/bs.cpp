#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a, b, c;
ll func(ll mid)
{
    ll ab = mid * (__gcd(a, b));
    ll bc = mid * (__gcd(c, b));
    ll ac = mid * (__gcd(a, c));
    ll abc = mid * (__gcd(__gcd(a, b), c));
    return mid / a + mid / b + mid / c - ab / (a * b) - bc / (c * b) - ac / (a * c) + abc / (a * b * c);
}
int32_t main()
{
    freopen("input.txt", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> a >> b >> c >> k;
        ll low = 1, mid;
        ll high = 1e18;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (func(mid) < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        cout << low << "\n";
    }
}