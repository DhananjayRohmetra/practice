#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    string pat;
    int x;
    vector<string> vec;
    char st[100];
    cin.getline(st, sizeof(st));
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> pat;
        vec.push_back(pat);
    }
    string str = "";
    int dp[100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] != ' ')
        {
            str += st[i];
        }
        else
        {
            str += '#';
        }
    }
    dp[0] = 0;
    for (int i = 1; i < 100; i++)
    {
        dp[i] += dp[i - 1];
    }
    for (int k = 0; k < vec.size(); k++)
    {
        int i = 1, len = 0;
        int lpslen = vec[k].length();
        int lps[lpslen + 1];
        memset(lps, 0, sizeof(lps));
        lps[0] = 0;
        while (i < lpslen)
        {
            if (vec[k][i] == vec[k][len])
            {
                lps[i]++;
                i++;
                len++;
            }
            else
            {
                if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }
        i = 0;
        int j = 0;
        int textlen = str.length();
        while (i < textlen)
        {
            if (str[i] == vec[k][j])
            {
                i++;
                j++;
            }
            if (j == lpslen)
            {
                cout << i - j;
                j = lps[j - 1];
            }
            if (str[i] != vec[k][j] && i < textlen)
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        cout << "\n";
    }
}