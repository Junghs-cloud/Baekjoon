#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string findStr = "UCPC";
	int index = 0;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == findStr[index])
		{
			index++;
			if (index == findStr.length())
			{
				break;
			}
		}
	}
	if (index == findStr.length())
	{
		cout << "I love UCPC" << "\n";
	}
	else
	{
		cout << "I hate UCPC" << "\n";
	}
	return 0;
}