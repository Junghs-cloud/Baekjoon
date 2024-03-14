#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 1;
	string str;
	cin >> N;
	cin >> str;
	int endIndex = N-1;
	int lastDiffIndex = -1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (str[i] == str[0])
		{
			endIndex = i;
			break;
		}
	}
	for (int i = 1; i <= endIndex; i++)
	{
		if (str[i] != str[0] && lastDiffIndex != i-1 )
		{
			answer++;
			lastDiffIndex = i;
		}
		else if (str[i] != str[0] && lastDiffIndex == i - 1)
		{
			lastDiffIndex = i;
		}
	}
	if (endIndex != N - 1)
	{
		answer++;
	}
	cout << answer << "\n";
	return 0;
}