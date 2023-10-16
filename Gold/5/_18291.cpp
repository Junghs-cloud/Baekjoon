#include <iostream>
using namespace std;

int main()
{
	int T, N;
	int x;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		if (N == 1)
		{
			cout << 1 << "\n";
		}
		else
		{
			x = N - 2;
			long long current = 2;
			long long answer = 1;
			while (x > 0)
			{
				if ((x & 1) == 1)
				{
					answer = answer * current % 1000000007;
					answer = answer % 1000000007;
				}
				x = x >> 1;
				current = current * current % 1000000007;
				current = current % 1000000007;
			}
			cout << answer << "\n";
		}
	}
	return 0;
}