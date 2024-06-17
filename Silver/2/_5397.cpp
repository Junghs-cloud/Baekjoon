#include <iostream>
#include <list>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string str;
		cin >> str;
		list<char> password;
		list<char>::iterator cursorPos = password.begin();

		for (int i = 0; i < str.length(); i++)
		{
			if (str.at(i) == '<')
			{
				if (cursorPos != password.begin())
				{
					cursorPos--;
				}
			}
			else if (str.at(i) == '>')
			{
				if (cursorPos != password.end())
				{
					cursorPos++;
				}
			}
			else if (str.at(i) == '-')
			{
				if (cursorPos != password.begin())
				{
					cursorPos = password.erase(--cursorPos);
				}
			}
			else
			{
				password.insert(cursorPos, str.at(i));
			}
		}
		for (cursorPos = password.begin(); cursorPos !=password.end(); cursorPos++)
		{
			cout << *cursorPos;
		}
		cout << "\n";
	}
	return 0;
}