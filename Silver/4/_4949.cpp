#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	stack<char> s;
	map<char, char> matchParens;
	matchParens.insert({')', '('});
	matchParens.insert({ '}', '{' });
	matchParens.insert({ ']', '[' });
	while (true)
	{
		getline(cin, str);
		bool isBalanced = true;
		if (str == ".")
		{
			break;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			{
				map<char, char>::iterator it = matchParens.find(str[i]);
				if (s.empty() || s.top() != it->second)
				{
					isBalanced = false;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (isBalanced == true && s.empty())
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
		while (!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}