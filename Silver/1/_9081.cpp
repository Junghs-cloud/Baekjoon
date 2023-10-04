#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		int strLength = str.length();
		char* arr = new char[strLength];
		for (int j = 0; j < strLength; j++)
		{
			arr[j] = str.at(j);
		}
		if (next_permutation(arr, arr + strLength))
		{
			for (int j = 0; j < strLength; j++)
			{
				cout << arr[j];
			}
			cout << "\n";
		}
		else
		{
			cout << str<<"\n";
		}
	}
	return 0;
}