#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int ugly[10001];
    ugly[0] = 1;
    int n2 = 2, n3 = 3, n5 = 5, next_ugly;
    int id2 = 0, id3 = 0, id5 = 0;
    for (int i = 1; i < 10001; i++)
    {
        next_ugly = min({n2, n3, n5});
        ugly[i] = next_ugly;
        if (next_ugly == n2)
        {
            id2++;
            n2 = ugly[id2] * 2;
        }
        if (next_ugly == n3)
        {
            id3++;
            n3 = ugly[id3] * 3;
        }
        if (next_ugly == n5)
        {
            id5++;
            n5 = ugly[id5] * 5;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout<<ugly[n-1]<<"\n";
    }
}