#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
string findWord;

void find(string word)
{
	string str1;
	string str2;
	for (int i = 0; i < (signed)word.length(); i++)
	{
		if (word[i] != ' ' && word[i] != '.')
		{
			if (word[i] >= 65 && word[i] <= 90)
			{
				str1.append(1, word[i] + 32);
			}
			else
			{
				str1.append(1, word[i]);
			}
		}
	}
	str1 = str1.substr(0, 10);
	str2 = str1;
	for (int i = 0; i < 26; i++)
	{
		str2 = str1;
		for (int j = 0; j < (signed) str1.length(); j++)
		{
			if (str1[j] + i >= 123)
			{
				str2[j] = str2[j] + i - 26;
			}
			else
			{
				str2[j] = str1[j] + i;
			}
		}
		if (str2 == str)
		{
			findWord = word;
		}
	}
}

int main()
{
	getline(cin, str);
	find("North London Collegiate School");
	find("Branksome Hall Asia");
	find("Korea International School");
	find("St. Johnsbury Academy");
	if (findWord == "North London Collegiate School")
	{
		cout << "NLCS" << "\n";
	}
	else if(findWord == "Branksome Hall Asia")
	{
		cout << "BHA" << "\n";
	}
	else if (findWord == "Korea International School")
	{
		cout << "KIS" << "\n";
	}
	else
	{
		cout << "SJA" << "\n";
	}
	return 0;
}