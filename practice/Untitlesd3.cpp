#include<bits/stdc++.h>
using namespace std;

int power(int x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}
int main()
{
int x = 5;
int y = 100000;
int p = 1000000007;
printf("Power is %u", (power(x, y-1, p)-power(x,y-2,p)+p)%p);
}


