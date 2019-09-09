#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, n, k;
    cin >> n >> k;
    ll arr[n + 1];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 0, bags = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + res >= k)
        {
            if (i == n - 1)
            {
                bags += (arr[i] + res + k - 1) / k;
            }
            else
            {
                if(res == 0)
                {
                    bags += (arr[i]) / k;
                    res = arr[i] - k * ((arr[i]) / k);   
                }
                else
                {
                    bags = bags + (res+k-1)/k +(arr[i]/k);
                    res = arr[i] - k * ((arr[i]) / k);
                }
            }
        }
        else
        {
            if (arr[i] == 0 && res != 0)
            {
                bags += 1;
                res = 0;
            }
            else
            {
                if (i == n - 1 && res+arr[i]>0)
                {
                    bags += 1;
                    res = 0;
                }
                else
                {
                    if (res != 0)
                    {
                        bags += 1;
                        res = 0;
                    }
                    else
                    {
                        res = arr[i];
                    }
                }
            }
        }
    }
    cout << bags;
}