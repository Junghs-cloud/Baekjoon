#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	long long answer = 1;
	for (int i = 0; i < str.length(); i++)
	{

		if (i == 0)
		{
			if (str.at(i) == 'c')
			{
				answer *= 26;
			}
			else
			{
				answer *= 10;
			}
		}
		else
		{
			if (str.at(i) == 'c' && str.at(i-1) == str.at(i))
			{
				answer *= 25;
			}
			else if (str.at(i) == 'c')
			{
				answer *= 26;
			}
			else if (str.at(i) == 'd' && str.at(i - 1) == str.at(i))
			{
				answer *= 9;
			}
			else
			{
				answer *= 10;
			}
			answer %= 1000000009;
		}
	}
	cout << answer << "\n";
	return 0;
}