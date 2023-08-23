#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int num;
	cin >> N;
	int* arr = new int[N];
	int max = 0;
	map<int, int> m;
	map<int, int>::iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		it = m.find(num);
		if (it == m.end())
		{
			m.insert({ num, 1 });
		}
		else
		{
			it->second++;
		}
	}
	for (it=m.begin(); it != m.end(); it++)
	{
		if ((it->second) != 1 && (it->second)> max)
		{
			max = it->second;
		}
	}

	if (max == 0)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << max << "\n";
	}

	return 0;
}