#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int str, in, ex;
        cin >> str >> in >> ex;
        int low = 0, mid;
        int high = ex, ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (str + mid > in + ex - mid)
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (ans == -1)
        {
            cout << "0\n";
        }
        else
        {
            cout << ex - ans + 1 << "\n";
        }
    }
}