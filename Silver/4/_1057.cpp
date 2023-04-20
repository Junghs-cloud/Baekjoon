#include <iostream>
using namespace std;

int main()
{
	int roundCount = 1;
	int N, a, b;
	cin >> N >> a >> b;
	while (true)
	{
		if (a % 2 == 1)
		{
			a = a / 2 + 1;
		}
		else
		{
			a = a / 2;
		}
		if (b % 2 == 1)
		{
			b = b / 2 + 1;
		}
		else
		{
			b = b / 2;
		}
		if (a == b)
		{
			break;
		}
		roundCount++;
	}
	cout << roundCount << "\n";
	return 0;
}