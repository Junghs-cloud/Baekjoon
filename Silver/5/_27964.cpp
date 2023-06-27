#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	string str;
	string token;
	getline(cin, str);
	istringstream ss(str);
	vector<string> cheeses;
	while (getline(ss, token, ' '))
	{
		if (token.length() >= 6 && token.substr(token.length() - 6) == "Cheese")
		{
			if (find(cheeses.begin(), cheeses.end(), token) == cheeses.end())
			{
				cheeses.push_back(token);
			}
		}
	}
	if (cheeses.size() >= 4)
	{
		cout << "yummy" << "\n";
	}
	else
	{
		cout << "sad" << "\n";
	}
	return 0;
}