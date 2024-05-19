#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;
	int N = str1.length();
	int M = str2.length();
	int** lengths = new int*[M+1];
	int maxLength = 0;
	for (int i = 0; i < M+1; i++)
	{
		lengths[i] = new int[N+1];
		for (int j = 0; j < N+1; j++)
		{
			lengths[i][j] = 0;
		}
	}
	for (int i = 1; i < M+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			if (str2.at(i - 1) == str1.at(j - 1))
			{
				lengths[i][j] = lengths[i - 1][j - 1] + 1;
				maxLength = max(maxLength, lengths[i][j]);
			}
			else
			{
				lengths[i][j] = 0;
			}
		}
	}
	cout << maxLength << "\n";
	return 0;
}