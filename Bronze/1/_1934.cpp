#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	int a, b;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> a >> b;
		int gcd = 1;
		if (a > b)
		{
			gcd = GCD(a, b);
		}
		else
		{
			gcd = GCD(b, a);
		}
		cout << a * b / gcd << "\n";
	}
	return 0;
}