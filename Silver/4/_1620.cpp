#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	string str;
	string command;
	map<int, string> pokemons;
	map<string, int> numbers;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		pokemons.insert({i, str});
		numbers.insert({str, i});
	}
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		bool isString = false;
		for (int j = 0; j < (signed) command.length(); j++)
		{
			if (command[j] >= 48 && command[j] <= 57)
			{
				continue;
			}
			else
			{
				isString = true;
				break;
			}
		}
		if (isString == false)
		{
			auto it = pokemons.find(stoi(command));
			cout << it->second << "\n";
		}
		else
		{
			auto it = numbers.find(command);
			cout << it->second << "\n";
		}
	}
	return 0;
}