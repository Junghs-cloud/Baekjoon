#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool* isPrime = new bool[100001];
	for (int i = 0; i < 100001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < sqrt(100001); i++)
	{
		for (int j = 2 * i; j < 100001; j += i)
		{
			isPrime[j] = false;
		}
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int num;
		cin >> num;
		map<int, int> m;
		map<int, int>::iterator it;
		while (isPrime[num] == false)
		{
			for (int i = 2; i <= sqrt(num); i++)
			{
				if (isPrime[i] == true && num % i == 0)
				{
					it = m.find(i);
					if (it == m.end())
					{
						m.insert({ i, 1 });
					}
					else
					{
						it->second++;
					}
					num /= i;
					break;
				}
			}
		}
		it = m.find(num);
		if (it == m.end())
		{
			m.insert({ num, 1 });
		}
		else
		{
			it->second++;
		}
		for (it = m.begin(); it != m.end(); it++)
		{
			cout << it->first << " " << it->second << "\n";
		}
	}
	return 0;
}