#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long gcd(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}

long long lcm(long long x, long long y)
{
	return x * y / gcd(x, y);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long a, b, L;
	cin >> a >> b >> L;
	long long alpha = lcm(a, b);
	long long k = L / alpha;
	long long c = -1;
	if (L % alpha != 0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		vector<long long> v;
		for (long long i = 1; i <= sqrt(alpha); i++)
		{
			if (alpha % i == 0)
			{
				v.push_back(i);
				v.push_back(alpha / i);
			}
		}
		sort(v.begin(), v.end());
		bool isFound = false;
		for (int i = 0; i < v.size(); i++)
		{
			c = k * v.at(i);
			long long gcdAlphaC = gcd(alpha, c);
			if (gcdAlphaC == v.at(i))
			{
				isFound = true;
				break;
			}
		}
		if (isFound == false)
		{
			cout << "-1" << "\n";
		}
		else
		{
			cout << c << "\n";
		}
	}
	return 0;
}