#include <iostream>
using namespace std;

int gcd(int x, int y)
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

int main()
{
	int x, y;
	cin >> x >> y;
	int GCD = gcd(x, y);
	int LCM = x * y/GCD;
	cout << GCD<<"\n" << LCM << "\n";
	return 0;
}