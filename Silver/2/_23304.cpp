#include <iostream>
#include <string>
using namespace std;

bool checkPelindrome(string str)
{
	bool isPelindrome = true;
	if (str.length() == 1)
	{
		return true;
	}
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			return false;
		}
	}
	if (str.length() % 2 == 0)
	{
		return checkPelindrome(str.substr(0, str.length() / 2)) && checkPelindrome(str.substr(str.length() / 2));
	}
	else
	{
		return checkPelindrome(str.substr(0, str.length() / 2)) && checkPelindrome(str.substr(str.length() / 2 + 1));
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	if (checkPelindrome(str) == true)
	{
		cout << "AKARAKA" << "\n";
	}
	else
	{
		cout << "IPSELENTI" << "\n";
	}
	return 0;
}