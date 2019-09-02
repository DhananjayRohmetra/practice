#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, row, col, flag = 0;
    int arr[501][501];
    int dp[501][501];
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ = summ ^ arr[i][0];
    }
    if (summ > 0)
    {
        cout << "TAK\n";
        for (int i = 0; i < n; i++)
        {
            cout << "1 ";
        }
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (arr[i][j] != arr[i][0])
                {
                    row = i;
                    col = j;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 1)
        {
             cout << "TAK\n";
            for (int i = 0; i < n; i++)
            {
                if (i == row)
                {
                    cout << col + 1  << " ";
                }
                else
                {
                    cout << "1 ";
                }
            }
        }
        else
        {
            cout << "NIE\n";
        }
    }
}