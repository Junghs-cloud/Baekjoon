#include <iostream>
using namespace std;

long long GCD(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return GCD(y, x % y);
	}
}

long long LCM(long long x, long long y)
{
	long long gcd = GCD(x, y);
	long long lcm = (x * y) / gcd;
	return lcm;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> K >> N;
	long long* arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	if (N >= 2)
	{
		long long lcm = LCM(arr[0], arr[1]);
		for (int i = 2; i < N; i++)
		{
			lcm = LCM(lcm, arr[i]);
		}
		cout << lcm - K << "\n";
	}

	return 0;
}