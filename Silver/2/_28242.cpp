#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<int, int> m1;
	map<int, int> m2;
	int a, b, c, d;
	bool canMake = false;
	for (int i = 1; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			m1.insert({ i, N / i });
		}
	}
	for (int i = 1; i <= sqrt(N+2); i++)
	{
		if ((N+2) % i == 0)
		{
			m2.insert({ i, (N+2) / i });
		}
	}
	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		for (map<int, int>::iterator iter = m2.begin(); iter != m2.end() && canMake == false; iter++)
		{
			a = it->first;
			c = it->second;
			b = iter->first;
			d = iter->second;
			if (a * d - b * c == N + 1)
			{
				cout << a <<" " << -b <<" " << c <<" " << d << "\n";
				canMake = true;
				break;
			}
			else if (b * c - a * d == N + 1)
			{
				cout << a << " " << b << " " << c << " " << -d << "\n";
				canMake = true;
				break;
			}
		}
	}
	if (canMake == false)
	{
		cout << -1 << "\n";
	}
	return 0;
}