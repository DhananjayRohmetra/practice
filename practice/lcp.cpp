#include <bits/stdc++.h>
using namespace std;
bool matchfull(int l, int r, string &s, vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = l; j <= r; j++)
        {
            if (v[i][j] != s[j])
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, i;
    cin >> n;
    vector<string> vec;
    string str;
    for (i = 0; i < n; i++)
    {
        cin >> str;
        vec.push_back(str);
    }
    int minn = 100000000;
    for (i = 0; i < vec.size(); i++)
    {
        if (vec[i].size() < minn)
        {
            minn = vec[i].size();
        }
    }
    int low = 0, mid;
    int high = minn;
    string prefix = "";
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (matchfull(low, mid, vec[0], vec))
        {
            prefix = prefix + vec[0].substr(low, mid - low + 1);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << prefix;
}