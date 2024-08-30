#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int start, end;
	int N;
	char a;
	string str;
	cin >> str;
	cin >> N;
	int length = str.length();
	int** alphabets = new int*[length+1];
	for (int i = 0; i < length+1; i++)
	{
		alphabets[i] = new int[26];
		for (int j = 0; j < 26; j++)
		{
			alphabets[i][j] = 0;
		}
	}
	for (int i = 0; i < length; i++)
	{
		int index = str.at(i) - 97;
		for (int j = 0; j < 26; j++)
		{
			if (j == index)
			{
				alphabets[i + 1][j] = alphabets[i][j]+1;
			}
			else
			{
				alphabets[i + 1][j] = alphabets[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a >> start >> end;
		int index = a - 97;
		cout << alphabets[end+1][index] - alphabets[start][index]<<"\n";
	}
	return 0;
}