#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<pair<int, int>> vec;
        int arr[n + 1], brr[n + 1];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i] >> brr[i];
            vec.push_back({arr[i], brr[i]});
        }
        sort(vec.begin(), vec.end(), sortbysec);
        int cnt = 1;
        int indexbomb = vec[0].second;
        for (int i = 1; i < n; i++)
        {
            if (vec[i].first > indexbomb)
            {
                indexbomb = vec[i].second;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}