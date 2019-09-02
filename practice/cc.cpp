#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    int ans = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int s = pq.top();
        pq.pop();
        s += pq.top();
        ans += s;
        pq.pop();
        pq.push(s);
    }
    cout << ans;
}