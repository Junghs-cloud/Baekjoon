#include <iostream>
using namespace std;

int main()
{
	long long x, y;
	long long winCount = 0;
	long long sum = 0;
	long long k = 0;
	bool canMake = true;
	cin >> x >> y;
	while (true)
	{
		sum += (++k);
		if (x + y == sum)
		{
			break;
		}
		else if (x + y < sum)
		{
			cout << "-1" << "\n";
			canMake = false;
			break;
		}
	}
	if (canMake == true)
	{
		for (long long i = k; i >= 1; i--)
		{
			if (i <= x)
			{
				x = x - i;
				winCount++;
			}
			else
			{
				y = y - i;
			}
		}
		cout << winCount << "\n";
	}
	return 0;
}