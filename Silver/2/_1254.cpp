#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPelindrome(string str)
{
	bool isPelindrome = true;
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str.at(i) != str.at(str.length()- 1 - i))
		{
			isPelindrome = false;
			break;
		}
	}
	return isPelindrome;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string newStr;
	cin >> str;
	newStr = str;
	for (int i = 0; i <= str.length(); i++)
	{
		newStr = str;
		string tail = str.substr(0, i);
		reverse(tail.begin(), tail.end());
		newStr += tail;
		if (isPelindrome(newStr) == true)
		{
			cout << newStr.length() << "\n";
			break;
		}
	}
	return 0;
}