#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, int> m;
	map<string, int>::iterator it;
	map<string, int>::iterator iter;
	int N, amount;
	string ingredient;
	bool isDelicious = false;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ingredient >> amount;
		it = m.find(ingredient);
		if (it == m.end())
		{
			m.insert({ingredient, amount});
		}
		else
		{
			it->second += amount;
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter == it)
			{
				continue;
			}
			int a = it->second;
			int b = iter->second;
			if ((int)(a * 1.618) == b || (int)(b * 1.618) == a)
			{
				isDelicious = true;
				break;
			}
		}
	}
	if (isDelicious == false)
	{
		cout << "Not Delicious..." << "\n";
	}
	else
	{
		cout << "Delicious!" << "\n";
	}
	return 0;
}