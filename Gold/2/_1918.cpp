#include <iostream>
#include <stack>
using namespace std;
stack<char> s;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 92)
		{
			cout << str[i];
		}
		else if (str[i] == '(' || str[i] == ')')
		{
			if (str[i] == '(')
			{
				s.push('(');
			}
			if (str[i] == ')')
			{
				while (!s.empty())
				{
					if (s.top() == '(')
					{
						s.pop();
						break;
					}
					cout << s.top();
					s.pop();
				}
			}
		}
		else
		{
			if (str[i] == '*' || str[i] == '/')
			{
				if (s.empty() == true)
				{
					s.push(str[i]);
				}
				else
				{
					if (s.top() == '*' || s.top() == '/')
					{
						while (!s.empty())
						{
							if (s.top() == '(')
							{
								break;
							}
							if (s.top() == '*' || s.top() == '/')
							{
								cout << s.top();
								s.pop();
								break;
							}
							cout << s.top();
							s.pop();
						}
						s.push(str[i]);
					}
					else
					{
						s.push(str[i]);
					}
				}

			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (s.empty() == true)
				{
					s.push(str[i]);
				}
				else
				{
					while (!s.empty())
					{
						if (s.top() == '(')
						{
							break;
						}
						cout << s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}