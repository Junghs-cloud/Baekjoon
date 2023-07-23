#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	while (true)
	{
		cin >> str;
		if (str == "end")
		{
			break;
		}
		else
		{
			bool isAcceptable = true;
			bool hasVowel = false;
			int vowelCount = 0;
			int consonantCount = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				{
					hasVowel = true;
					vowelCount++;
					consonantCount = 0;
					if (vowelCount == 3)
					{
						isAcceptable = false;
						break;
					}
				}
				else
				{
					consonantCount++;
					vowelCount = 0;
					if (consonantCount == 3)
					{
						isAcceptable = false;
						break;
					}
				}
				if (i >= 1)
				{
					if (str[i - 1] == str[i] && str[i]!='e' && str[i]!='o')
					{
						isAcceptable = false;
						break;
					}
				}
			}
			if (hasVowel == false || isAcceptable==false)
			{
				cout << "<" << str << "> is not acceptable.\n";
			}
			else if (isAcceptable == true)
			{
				cout << "<" << str << "> is acceptable.\n";
			}
		}
	}
	return 0;
}