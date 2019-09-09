#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define write(v)                       \
	for (int i = 0; i < v.size(); i++) \
		cout << v[i] << " ";
#define read(v)                        \
	for (int i = 0; i < v.size(); i++) \
		cin >> v[i];
#define write1(v)                      \
	for (int i = 1; i < v.size(); i++) \
		cout << v[i] << " ";
#define read1(v)                       \
	for (int i = 1; i < v.size(); i++) \
		cin >> v[i];
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
int main()
{
	long long int flag = 0, s1, n, x, k, d = 0, s, l1, l2, i;
	double f;
	cin >> n >> x >> k;
	long long int arr[n + 1];
	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			flag = 1;
		}
	}
	sort(arr, arr + n);
	for (i = 0; i < n; i++)
	{
		f = arr[i];
		s = max(f, (k - 1 + ceil(double(arr[i]) / double(x))) * x);
		s1 = (k - 1 + ceil(double(arr[i]) / double(x))) * x + x - 1;
		l1 = lower_bound(arr, arr + n, s) - arr;
		l2 = upper_bound(arr, arr + n, s1) - arr;
		d += l2 - l1;
	}
	if (flag == 0 && arr[0] == x && k == 1)
	{
		cout << n * n;
	}
	else
	{

		cout << d;
	}
	return 0;
}
