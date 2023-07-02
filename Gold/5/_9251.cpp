#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int length1 = (signed) str1.length();
	int length2 = (signed) str2.length();
	int** arr = new int* [length2+1];
	for (int i = 0; i < length2 + 1; i++)
	{
		arr[i] = new int[length1+1];
		for (int j = 0; j < length1+1; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= length2; i++)
	{
		for (int j = 1; j <= length1; j++)
		{
			if (str2[i - 1] == str1[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
			}
		}
	}
	cout << arr[length2][length1];
	return 0;
}