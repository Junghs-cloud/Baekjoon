#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	int testCaseNum = 1;
	stack<char> s;
	while (true)
	{
		int answerCount = 0;
		cin >> str;
		if (str.find('-') != string::npos)
		{
			break;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '{')
			{
				s.push(str[i]);
			}
			else
			{
				if (s.empty())
				{
					answerCount++;
					s.push('(');
				}
				else
				{
					s.pop();
				}
			}
		}
		answerCount += s.size() / 2;
		std::cout << testCaseNum << ". " << answerCount << "\n";
		testCaseNum++;
		while (!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}