#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()

int main()
{
	int r, i, j, n, m, cnt = 1, x = 1, glb = 0, counter = 1, xx;
	cin >> n >> m;
	int www[n * m + 2];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> xx;
			www[counter] = xx;
			counter++;
		}
	}
	int arr[n + 1][n + 1];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			arr[i][j] = cnt;
			cnt++;
		}
	}
	int prod = m * n;
	int r1 = m - 1;
	int r2 = n - 1;
	while (r1 > 0 || r2 > 0)
	{
		int f = x;

		for (int g = x; g < x + r1; g++)
		{
			if (glb >= m * n)
			{
				break;
			}
			glb++;
			cout << www[g] << " ";
		}
		f = f + r1;
		int h = f;
		for (int i = 1; i <= r2; i++)
		{
			if (glb >= m * n)
			{
				break;
			}
			glb++;
			cout << www[f] << " ";
			f = h + i * m;
		}

		for (int k = f; k >= f - (r1 - 1); k--)
		{
			if (glb >= m * n)
			{
				break;
			}
			glb++;
			cout << www[k] << " ";
		}
		f = f - r1;
		if (r2 == 1)
		{
			glb++;
			cout << www[f] << " ";
		}
		else
		{

			for (int i = f; i >= f - (r2 - 2) * m; i -= m)
			{

				if (glb >= prod)
				{
					break;
				}
				cout << www[i] << " ";
				glb++;
			}
		}

		f = f - (r2 - 1) * m;
		//cout<<glb<<" "<<prod<<" ";
		if (glb == prod)
		{
			break;
		}

		cout << www[f] << " ";
		glb++;
		x = f + 1;
		r1 -= 2;
		r2 -= 2;
	}
	if (n % 2 != 0 && m % 2 != 0)
	{
		cout << x;
	}
}
