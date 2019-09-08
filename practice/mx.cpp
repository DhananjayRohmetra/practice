#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, prev, i;
    cin >> n >> x;
    ll maknum = 0, num, cnt = 0;
    ll arr[n + 1];
    memset(arr, 0, sizeof(arr));
    while (maknum < x)
    {
        num = 1;
        for (int i = 1; i <= 64; i++)
        {
            if (num * 2 > x - maknum)
            {
                break;
            }
            num = num * 2;
        }
        maknum += num;
        arr[cnt] = num;
        cnt++;
    }

    if ((n - cnt) % 2 == 0)
    {
        for (i = cnt; i < n; i++)
            arr[i] = 1;
    }
    else
    {
        arr[0] = arr[0] ^ 1;
        for (i = cnt; i < n; i++)
            arr[i] = 1;
    }
    sort(arr, arr + n);
    if (n == 1)
    {
        cout << x;
    }
    else
    {
        if (x == 1)
        {
            if (n == 2)
            {
                cout << "2 3";
            }
            else
            {
                if (n % 2 != 0)
                {
                    for (int i = 0; i < n; i++)
                        cout << "1 ";
                }
                else
                {
                    for (int i = 0; i < n - 2; i++)
                    {
                        cout << "1 ";
                    }
                    cout << "2 3";
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        }
    }
}