#include <bits/stdc++.h>
using namespace std;
struct node
{
    string str;
    int len;
};
int check_adjacent(string &a, string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }
    }
    if (cnt == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    set<string> D;
    int n;
    cin >> n;
    string str, target, start;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        D.insert(str);
    }
    cin >> start >> target;
    queue<node> q;
    node source;
    source.str = start;
    source.len = 0;
    q.push(source);

    while (!q.empty())
    {
        node front = q.front();
        q.pop();
        if (front.str == target)
        {
            cout << front.str;
            break;
        }
        for (auto it = D.begin(); it != D.end(); it++)
        {
            string temp = *it;

            if (check_adjacent(front.str, temp) != 0)
            {
                cout << front.str << "--";
                node x;
                x.str = temp;
                x.len = front.len + 1;
                q.push(x);
                D.erase(temp);
            }
        }
    }
}