#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long K, A, B;
	cin >>K>> A >> B;
	if (A > 0)
	{
		cout << B / K - (A - 1) / K << "\n";
	}
	else if (A == 0)
	{
		cout << B / K + 1<< "\n";
	}
	else if (A < 0 && B < 0)
	{
		cout << -A / K - (- B -  1) / K << "\n";
	}
	else if (A < 0 && B == 0)
	{
		cout << -A / K + 1 << "\n";
	}
	else //A < 0 && B > 0
	{
		cout << B / K + (- A / K) + 1 << "\n";
	}
	return 0;
}