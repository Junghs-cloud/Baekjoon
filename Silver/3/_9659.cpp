#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;
	if (N % 2 == 0)
	{
		cout << "CY" << "\n";
	}
	else
	{
		cout << "SK" << "\n";
	}
	return 0;
}