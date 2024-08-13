#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
stack<char> temp;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string makeString = "";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		s.push(str[i]);
		if (str[i] == 'P' && s.size() >= 4)
		{
			makeString = "";
			for (int j = 0; j < 4; j++)
			{
				char current = s.top();
				makeString += current;
				s.pop();
				temp.push(current);
			}
			if (makeString == "PAPP")
			{
				s.push('P');
				for (int j = 0; j < 4; j++)
				{
					temp.pop();
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					s.push(temp.top());
					temp.pop();
				}
			}
		}
	}
	if (s.size() == 1 && s.top() == 'P')
	{
		cout << "PPAP";
	}
	else
	{
		cout << "NP" << "\n";
	}
	return 0;
}