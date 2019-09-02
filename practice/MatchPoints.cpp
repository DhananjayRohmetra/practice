#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, z;
    cin >> n >> z;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int last = n - 1, count = 0, st, ed;
    if (n % 2 == 0)
    {
        st = n / 2 - 1;
        ed = n / 2;
    }
    else
    {
        st = n / 2;
        ed = n / 2 + 1;
    }
    for (int i = st; i >= 0; i--)
    {
        if (arr[last] >= arr[i] + z && last >= ed)
        {
            count++;
            last--;
        }
    }
    cout << count;
}