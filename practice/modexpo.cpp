#include <bits/stdc++.h>
using namespace std;

int recur(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return recur(x * x, n / 2);
    }
    else
    {
        return x * recur(x * x, (n - 1) / 2);
    }
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << recur(x, n);
}

