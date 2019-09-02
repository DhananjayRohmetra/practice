#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int ans = -1;
    int tlen = t.length();
    int slen = s.length();
    int fr[tlen + 1];
    int ba[tlen + 1];
    int si = 0, ti = 0;
    while (ti != tlen)
    {
        if (t[ti] == s[si])
        {
            fr[ti] = si;
            ti++;
        }
        si++;
    }

    si = slen - 1;
    ti = tlen - 1;
    while (ti != -1)
    {
        if (t[ti] == s[si])
        {
            ba[ti] = si;
            ti--;
        }
        si--;
    }

    ans = max({ans, slen - fr[tlen - 1] - 1, ba[0]});
    for (int i = 0; i < tlen - 1; i++)
    {
        ans = max(ans, ba[i + 1] - fr[i] - 1);
    }
    cout << ans;
}