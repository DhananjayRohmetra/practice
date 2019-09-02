#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j, k;
        cin >> n;
        string str;
        set<string> st;
        for (i = 0; i < n; i++)
        {
            cin >> str;
            st.insert(str);
        }
        string s;
        cin >> s;
        bool dp[1001][1001];
        memset(dp, false, sizeof(dp));
        for (i = 0; i < s.size(); i++)
        {
            if (st.find(s.substr(i, 1)) != st.end())
            {
                dp[i][i] = true;
            }
        }

        for (int l = 2; l <= s.size(); l++)
        {
            for (i = 0; i < s.size() - l + 1; i++)
            {
                j = i + l - 1;
                if (l == 2)
                {
                    if (st.find(s.substr(i, l)) != st.end() || s[i] == s[i + 1])
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if (st.find(s.substr(i, l)) != st.end())
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        for (k = i; k <= j - 1; k++)
                        {
                            if (dp[i][k] && dp[k + 1][j])
                            {
                                dp[i][j] = true;
                            }
                        }
                    }
                }
            }
        }
        for (i = 0; i < s.size(); i++)
        {
            for (j = 0; j < s.size(); j++)
            {
                //cout << dp[i][j] << " ";
            }
            //cout << "\n";
        }
        if (dp[0][s.size() - 1])
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}