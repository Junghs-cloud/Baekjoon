#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int* counts = new int[26];
		bool isCorrect = true;
		for (int i = 0; i < 26; i++)
		{
			counts[i] = 0;;
		}
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			int index = str.at(i) - 65;
			counts[index]++;
			if (counts[index] == 3)
			{
				counts[index] = 0;
				if (i < str.length()-1 && str.at(i + 1) == str.at(i))
				{
					i++;
				}
				else
				{
					isCorrect = false;
					break;
				}
			}

		}
		if (isCorrect == true)
		{
			cout << "OK" << "\n";
		}
		else
		{
			cout << "FAKE" << "\n";
		}
	}
	return 0;
}