#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	map<string, int> species;
	string str="";
	int totalCount = 0;
	while (getline(cin, str))
	{
		if (str == "\0")
		{
			break;
		}
		auto iter = species.find(str);
		if (iter == species.end())
		{
			species.insert({ str, 1 });
		}
		else
		{
			iter->second++;
		}
		totalCount++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = species.begin(); it !=species.end() ; it++)
	{
		double speciesCount = it->second;
		double percent = speciesCount / totalCount * 100;
		cout << it-> first << " " << percent << "\n";
	}
	return 0;
}