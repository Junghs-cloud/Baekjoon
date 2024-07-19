#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	stack<char> s;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j= 0; j < str.length(); j++)
		{
			if (s.empty())
			{
				s.push(str.at(j));
			}
			else
			{
				if (s.top() == str.at(j))
				{
					s.pop();
				}
				else
				{
					s.push(str.at(j));
				}
			}
		}
		if (s.empty())
		{
			answer++;
		}
		else
		{
			while (!s.empty())
			{
				s.pop();
			}
		}
	}
	cout << answer << "\n";
	return 0;
}