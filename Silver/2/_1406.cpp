#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	string str;
	char command;
	char insertChar;
	list<char> line;
	int N;
	cin >> str;
	cin >> N;
	for (int i = 0; i < (signed) str.length(); i++)
	{
		line.push_back(str[i]);
	}
	list<char>::iterator cursor = line.end();
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == 'P')
		{
			cin >> insertChar;
			line.insert(cursor, insertChar);
		}
		else if (command == 'L')
		{
			if (cursor != line.begin())
			{
				cursor--;
			}

		}
		else if (command == 'D')
		{
			if (cursor != line.end())
			{
				cursor++;
			}
		}
		else
		{
			if (cursor != line.begin())
			{
				cursor--;
				cursor = line.erase(cursor);
			}
		}
	}
	for (list<char>::iterator iter = line.begin(); iter != line.end(); iter++)
	{
		cout << *iter;
	}
	cout << "\n";
	return 0;
}