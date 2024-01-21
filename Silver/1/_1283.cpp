#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	string token;
	bool* alphabets = new bool[26];
	cin >> N;
	cin.ignore();
	for (int i = 0; i < 26; i++)
	{
		alphabets[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		istringstream ss(str);
		bool hasKey = false;
		string keyToken = "";
		while (getline(ss, token, ' ') && hasKey == false)
		{
			int index = (tolower(token[0])) - 97;
			if (alphabets[index] == false)
			{
				alphabets[index] = true;
				hasKey = true;
				keyToken = token;
			}
		}
		if (hasKey == false)
		{
			for (int j = 0; j < str.length(); j++)
			{
				int index = (tolower(str[j])) - 97;
				if (str[j] != ' ' && alphabets[index] == false)
				{
					alphabets[index] = true;
					hasKey = true;
					cout << str.substr(0, j) << "[" << str[j] <<"]" << str.substr(j + 1)<<"\n";
					break;
				}
			}
			if (hasKey == false)
			{
				cout << str<<"\n";
			}
		}
		else
		{
			int index = str.find(keyToken);
			cout << str.substr(0, index) << "[" << str[index] << "]" << str.substr(index + 1)<<"\n";
		}
	}
	return 0;
}