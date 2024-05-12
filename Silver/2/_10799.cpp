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
	long long answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '(')
		{
			s.push('(');
		}
		else
		{
			s.pop();
			if (str.at(i - 1) == '(')
			{
				answer += s.size();
			}
			else
			{
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}