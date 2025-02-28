#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getGCD(int x, int y)
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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		int answer = 0;
		cin >> N;
		for (int i = 1; i <= sqrt(N); i++)
		{
			if (N % i == 0)
			{
				int j = N / i;
				int gcd = getGCD(i, j);
				if (gcd == 1)
				{
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}