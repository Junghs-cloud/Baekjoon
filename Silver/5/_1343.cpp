#include <iostream>
#include <string>
using namespace std;

int main()
{
	int continuous = 0;
	bool flag = true;
	string str;
	string answer;
	cin >> str;
	for (int i = 0; i < (signed) str.length(); )
	{
		int j = i + 1;
		int k = i;
		continuous = 1;
		if (str[i] == 'X')
		{
			for (j = i + 1; j < (signed) str.length(); j++)
			{
				if (str[j] == '.')
				{
					break;
				}
				else
				{
					continuous++;
				}
			}
			i = j;
			while (continuous != 0)
			{
				if (continuous >= 4)
				{
					continuous -= 4;
					answer.append("AAAA");
				}
				else if (continuous == 2)
				{
					answer.append("BB");
					continuous -= 2;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		else
		{
			answer.append(".");
			i++;
		}
	}
	if (flag == true)
	{
		cout << answer << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
	return 0;
}