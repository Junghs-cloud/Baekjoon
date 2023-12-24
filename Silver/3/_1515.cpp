#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	string makeStr = "";
	int currentNum = 1;
	while (true)
	{
		makeStr += to_string(currentNum);
		bool canMake = true;
		int index = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (makeStr.find(str[i], index) == string::npos)
			{
				canMake = false;
			}
			else
			{
				index = makeStr.find(str[i], index)+1;
			}
		}
		if (canMake == true)
		{
			cout << currentNum << "\n";
			break;
		}
		currentNum++;
	}
	return 0;
}