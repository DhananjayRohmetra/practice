#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int root = INT_MIN, flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < root)
            {
                cout << "false";
                flag = 1;
                break;
            }
            while (!st.empty() && arr[i] > st.top())
            {

                root = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        if (flag == 0)
        {
            cout << "True";
        }
    }
}