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
	long long x, y;
	cin >> x >> y;
	long long gcd = getGCD(x, y);
	string answer = "";
	answer.append(gcd, '1');
	cout << answer << "\n";
	return 0;
}