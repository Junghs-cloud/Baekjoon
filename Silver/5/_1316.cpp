#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string str;
	int* alphabets = new int[26];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			alphabets[j] = 0;
		}
		cin >> str;
		char prev = str[0];
		bool isGroupWord=true;
		for (int j = 0; j < str.length(); j++)
		{
			int index = str[j] - 97;
			if (alphabets[index] != 0 && str[j] != prev)
			{
				isGroupWord = false;
				break;
			}
			alphabets[index]++;
			prev = str[j];
		}
		if (isGroupWord == true)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}