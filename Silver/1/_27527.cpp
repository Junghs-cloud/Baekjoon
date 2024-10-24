#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	map<int, int> m;
	map<int, int>::iterator it;
	int* arr = new int[N+1];
	int standard = 0;
	if ((9 * M) % 10 == 0)
	{
		standard = 9 * M / 10;
	}
	else
	{
		standard = 9 * M / 10;
		standard++;
	}
	bool canMake = false;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= M; i++)
	{
		it = m.find(arr[i]);
		if (it == m.end())
		{
			m.insert({ arr[i], 1 });
			if (1 >= standard)
			{
				canMake = true;
				break;
			}
		}
		else
		{
			it->second++;
			if (it->second >= standard)
			{
				canMake = true;
				break;
			}
		}
	}
	if (canMake == false)
	{
		for (int i = M+1; i <= N; i++)
		{
			if (arr[i] == arr[i - M])
			{
				continue;
			}
			else
			{
				it = m.find(arr[i - M]);
				it->second--;

				it = m.find(arr[i]);
				if (it == m.end())
				{
					m.insert({ arr[i], 1 });
					if (1 >= standard)
					{
						canMake = true;
						break;
					}
				}
				else
				{
					it->second++;
					if (it->second >= standard)
					{
						canMake = true;
						break;
					}
				}
			}
		}
	}
	if (canMake == true)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}