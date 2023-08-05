#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	cin.ignore();
	for (int t= 0; t < T; t++)
	{
		string str;
		getline(cin, str);
		int* arr = new int[26];
		for (int j = 0; j < 26; j++)
		{
			arr[j] = 0;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 97 && str[i] <= 122)
			{
				int index = str[i] - 97;
				arr[index]++;
			}
			else if (str[i] >= 65 && str[i] <= 90)
			{
				int index = str[i] - 65;
				arr[index]++;
			}
			else
			{
				continue;
			}
		}
		int minCount = 999999999;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] < minCount)
			{
				minCount = arr[i];
			}
		}
		cout << "Case "<<t+1<<": ";
		if (minCount == 0)
		{
			cout << "Not a pangram\n";
		}
		else if (minCount == 1)
		{
			cout << "Pangram!\n";
		}
		else if (minCount == 2)
		{
			cout << "Double pangram!!\n";
		}
		else
		{
			cout << "Triple pangram!!!\n";
		}
	}
	return 0;
}