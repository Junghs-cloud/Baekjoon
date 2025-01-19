#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	while (str != "")
	{
		if (str.substr(0, 2) == "pi")
		{
			str = str.substr(2);
		}
		else if (str.substr(0, 2) == "ka")
		{
			str = str.substr(2);
		}
		else if (str.substr(0, 3) == "chu")
		{
			str = str.substr(3);
		}
		else
		{
			break;
		}
	}
	if (str == "")
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}