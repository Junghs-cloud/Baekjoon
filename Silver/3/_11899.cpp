#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	stack<char> s;
	int answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '(')
		{
			s.push('(');
		}
		else
		{
			if (s.empty())
			{
				answer++;
			}
			else
			{
				s.pop();
			}
		}
	}
	answer += s.size();
	std:: cout << answer << "\n";
	return 0;
}