#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string str;
	int* firstStr = new int[26];
	cin >> str;
	int* strChar = new int[26];
	int answer = 0;
	int firstStrLength = str.length();
	for (int i = 0; i < 26; i++)
	{
		firstStr[i] = 0;
	}
	for (int i = 0; i < str.length(); i++)
	{
		int c = str[i] - 65;
		firstStr[c]++;
	}
	for (int i = 1; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < 26; j++)
		{
			strChar[j] = 0;
		}
		for (int j = 0; j < str.length(); j++)
		{
			int c = str[j] - 65;
			strChar[c]++;
		}
		bool b = false;
		bool isSimilar = true;
		int plusMinus = 0;
		for (int i = 0; i < 26; i++)
		{
			if (strChar[i] == firstStr[i])
			{
				continue;
			}
			else
			{
				if (str.length() + 1 == firstStrLength)
				{
					if (b == false && strChar[i] + 1 == firstStr[i])
					{
						b = true;
					}
					else
					{
						isSimilar = false;
						break;
					}
				}
				else if (str.length() - 1 == firstStrLength)
				{
					if (b == false && strChar[i] - 1 == firstStr[i])
					{
						b = true;
					}
					else
					{
						isSimilar = false;
						break;
					}
				}
				else if (str.length() == firstStrLength)
				{
					if (b==false && strChar[i] + 1 == firstStr[i])
					{
						b = true;
						plusMinus++;
					}
					else if (b==false && strChar[i] - 1 == firstStr[i])
					{
						b = true;
						plusMinus--;
					}
					else if (b == true && strChar[i] - 1 == firstStr[i])
					{
						plusMinus--;
						if (plusMinus != 0)
						{
							isSimilar = false;
							break;
						}
					}
					else if (b == true && strChar[i] + 1 == firstStr[i])
					{
						plusMinus++;
						if (plusMinus != 0)
						{
							isSimilar = false;
							break;
						}
					}
					else
					{
						isSimilar = false;
						break;
					}
				}
				else
				{
					isSimilar = false;
					break;
				}
			}
		}
		if (isSimilar == true)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}