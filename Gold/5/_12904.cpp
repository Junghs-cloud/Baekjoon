#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	string complete;
	cin >> str;
	cin >> complete;
	while (complete.length() != str.length())
	{
		int length = complete.length();
		if (complete[length - 1] == 'B')
		{
			complete = complete.substr(0, length-1);
			reverse(complete.begin(), complete.end());
		}
		else
		{
			complete = complete.substr(0, length - 1);
		}
	}
	if (complete == str)
	{
		cout << "1"<<"\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}