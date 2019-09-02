#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long int n, sum = 0;
    cin >> n;
    string s;
    map<string, long long int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        long long int s = it->second;
        sum += ((s) * (s - 1)) / 2;
    }
    cout << sum;
}