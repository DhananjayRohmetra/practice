#include <bits/stdc++.h>
using namespace std;
int prime[1043];
void sieve()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i * i <= 1014; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 2 * i; j <= 1014; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    sieve();
    int nextprime[1009];
    for (int j = 3; j <= 1000; j++)
    {
        for (int i = j; i <= 1014; i++)
        {
            if (!prime[i])
            {
                nextprime[j] = i;
                break;
            }
        }
    }
    if (nextprime[n] == n)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (i + 1 <= n)
            {
                cout << i << " " << i + 1 << "\n";
            }
            else
            {
                cout << n << " "
                     << "1\n";
            }
        }
    }
    else
    {
        cout << nextprime[n] << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (i + 1 <= n)
            {
                cout << i << " " << i + 1 << "\n";
            }
            else
            {
                cout << n << " "
                     << "1\n";
            }
        }

        int leftedges = nextprime[n] - n;
        for (int i = 1; i <= leftedges; i++)
        {
            cout << i << " " << i + n / 2 << "\n";
        }
    }
}