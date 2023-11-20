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
	int* arr = new int[N];
	map<int, int> m;
	map<int, int>::iterator it;
	int* answer = new int[N];
	for (int i = 0; i < N; i++)
	{
		answer[i] = 0;
		cin >> arr[i];
		it = m.find(arr[i]);
		if (it == m.end())
		{
			m.insert({ arr[i] , 1 });
		}
		else
		{
			it->second++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= sqrt(arr[i]); j++)
		{
			if (arr[i] == 1)
			{
				it = m.find(1);
				answer[i] += it->second - 1;
				continue;
			}
			if (arr[i] % j == 0)
			{
				int b = arr[i] / j;
				it = m.find(j);
				if (it != m.end())
				{
					answer[i] += it->second;
				}
				if (j  != b)
				{
					it = m.find(b);
					if (it != m.end())
					{
						if (b == arr[i])
						{
							answer[i] += it->second - 1;
						}
						else
						{
							answer[i] += it->second;
						}
					}
				}
			}

		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}