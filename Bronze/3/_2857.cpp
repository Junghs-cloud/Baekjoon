#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<int> FBI;
	for (int i = 1; i <= 5; i++)
	{
		cin >> str;
		if (str.find("FBI") != string::npos)
		{
			FBI.push_back(i);
		}
	}
	if (FBI.empty())
	{
		cout << "HE GOT AWAY!" << "\n";
	}
	for (int i = 0; i < FBI.size(); i++)
	{
		cout << FBI.at(i) << " ";
	}
	return 0;
}