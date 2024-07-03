#include <iostream>
using namespace std;

int GCD(int x, int y)
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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C, D;
	cin >> A >> B;
	cin >> C >> D;
	int numerator = A * D + B * C;
	int denominator = B * D;
	while (GCD(numerator, denominator) != 1)
	{
		int gcd = GCD(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
	cout << numerator <<" " << denominator << "\n";
	return 0;
}