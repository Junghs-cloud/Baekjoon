#include <iostream>
using namespace std;
int* pi = new int[5001];

int getPiAndMaxLength(string patternStr)
{
	int j = 0;
	int length = 0;
	for (int i = 1; i < patternStr.length(); i++)
	{
		while (j > 0 && patternStr.at(i) != patternStr.at(j))
		{
			j = pi[j - 1];
		}
		if (patternStr.at(i) == patternStr.at(j))
		{
			j++;
			pi[i] = j;
		}
		length = max(length, pi[i]);
	}
	return length;
}

void resetPi()
{
	for (int i = 0; i < 5001; i++)
	{
		pi[i] = 0;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int answer = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		resetPi();
		string subsString = str.substr(i, str.length());
		int currentMaxLength = getPiAndMaxLength(subsString);
		answer = max(answer, currentMaxLength);
	}
	cout << answer << "\n";
	return 0;
}