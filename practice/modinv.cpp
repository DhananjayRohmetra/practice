#include <bits/stdc++.h>
using namespace std;
int x, y;
pair<int, int> recur(int a, int b)
{
    if (b == 0)
    {
        return pair<int, int>(1, 0);
    }
    else
    {
        pair<int, int> p1 = recur(b, a % b);
        x = p1.second;
        y = p1.first - floor((a * 1.0) / b) * p1.second;
        return pair<int, int>(x, y);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    pair<int, int> p1 = recur(a, b);
    cout << p1.first << " " << p1.second;
}
