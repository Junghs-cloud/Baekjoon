#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	string startStr = str;
	int answer = 0;
	while (true)
	{
		answer++;
		int sum = 0;
		if (str.length() == 1)
		{
			str = "0" + str;
		}
		for (int i = 0; i < str.length();i++)
		{
			sum += str.at(i) - 48;
		}
		int lastOfSum = sum % 10;
		str = str.at(str.length() - 1) + to_string(lastOfSum);
		if (stoi(str) == stoi(startStr))
		{
			cout << answer << "\n";
			break;
		}
	}

	return 0;
}