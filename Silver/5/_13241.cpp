#include <iostream>
using namespace std;

long long getGCD(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return getGCD(y, x % y);
	}
}

int main()
{
	long long A, B;
	cin >> A >> B;
	long long gcd = 0;
	if (A > B)
	{
		gcd = getGCD(A, B);
	}
	else
	{
		gcd = getGCD(B, A);
	}
	cout << A * B / gcd;
	return 0;
}