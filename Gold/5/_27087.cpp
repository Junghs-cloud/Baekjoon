#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, a, b, c, p;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b >> c >> p;
		bool canMake = false;

		if (canMake == false && (a % p == 0) && (b % p == 0))
		{
			canMake = true;
		}
		if (canMake == false && (a % p == 0) && (c % p == 0))
		{
			canMake = true;
		}
		if (canMake == false && (b % p == 0) && (c % p == 0))
		{
			canMake = true;
		}
		if (canMake == false)
		{
			cout << "0" << "\n";
		}
		else
		{
			cout << "1" << "\n";
		}
	}
	return 0;
}