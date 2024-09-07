#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	int answer = 51;
	cin >> str1 >> str2;
	for (int i = 0; i <= str2.length() - str1.length(); i++)
	{
		string str = str2.substr(i, str1.length());
		int count = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str1[j] != str[j])
			{
				count++;
			}
		}
		answer = min(answer, count);
	}
	cout << answer << "\n";
	return 0;
}