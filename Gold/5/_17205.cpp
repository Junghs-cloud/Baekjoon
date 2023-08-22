#include <iostream>
#include <cmath>
using namespace std;

long long check(long long length)
{
	if (length == 1)
	{
		return 1;
	}
	else
	{
		return (long long)pow(26, length - 1);
	}
}

int main()
{
	int N;
	string str;
	cin >> N;
	cin >> str;
	long long strLength = str.length();
	int firstLetterIndex = str[0] - 97;
	long long answer = 0;

	for (int i = 0; i < firstLetterIndex; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer += check(j);
		}
	}
	answer++;
	for (int k = 1; k < strLength;k++)
	{
		int letterIndex = str[k] - 97;
		for (int i = 0; i < letterIndex; i++)
		{
			for (int j = 1; j <= N - k; j++)
			{
				answer += check(j);
			}
		}
		answer++;
	}
	cout << answer << "\n";
	return 0;
}