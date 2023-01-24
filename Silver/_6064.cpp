#include <iostream>
using namespace std;

int gcd(int M, int N)
{
	if (N == 0)
	{
		return M;
	}
	else
	{
		return gcd(N, M % N);
	}
}

int lcd(int M, int N)
{
	return (M * N / gcd(M,N));
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, M, N, x, y;
	bool isFind;
	int a, year, lastYear;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		a = 0;
		year = 0;
		isFind = false;
		cin >> M >> N >> x >> y;
		lastYear = lcd(M, N);
		for (int i = 0; year <= lastYear; i++)
		{
			year = i * M + x;
			if ((year - y) % N == 0)
			{
				cout << year << "\n";
				isFind = true;
				break;
			}
		}
		if (isFind == false)
		{
			cout << "-1" << "\n";
		}
	}
	return 0;
}