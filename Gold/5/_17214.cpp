#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	istringstream ss;
	string token;
	if (str[0] == '-')
	{
		cout << "-";
		str = str.substr(1, str.length() - 1);
	}
	istringstream is(str);
	if (str.find('-') != string::npos)
	{
		while (getline(is, token, '-'))
		{
			if (token.find('x') != string::npos)
			{
				string coefficientStr = token.substr(0, token.length() - 1);
				int coefficient = stoi(coefficientStr);
				if (coefficient == 2)
				{
					cout << "xx-";
				}
				else
				{
					cout << coefficient / 2 << "xx-";
				}
			}
			else
			{
				if (token != "0")
				{
					if (token == "1")
					{
						cout << "x+";
					}
					else
					{
						cout << token << "x+";
					}
				}

			}
		}
		cout << "W" << "\n";
	}
	else
	{
		while (getline(is, token, '+'))
		{
			if (token.find('x') != string::npos)
			{
				string coefficientStr = token.substr(0, token.length() - 1);
				int coefficient = stoi(coefficientStr);
				if (coefficient == 2)
				{
					cout << "xx+";
				}
				else
				{
					cout << coefficient / 2 << "xx+";
				}
			}
			else
			{
				if (token != "0")
				{
					if (token == "1")
					{
						cout << "x+";
					}
					else
					{
						cout << token << "x+";
					}
				}
			}
		}
		cout << "W" << "\n";
	}
	return 0;
}