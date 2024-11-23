#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int N, M;
	cin >> str;
	cin >> N;
	M = str.length();
	bool* dp = new bool[M + 1];
	string* inputs = new string[N];
	for (int i = 0; i < M; i++)
	{
		dp[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> inputs[i];
	}
	for (int index = 0; index < M; index++)
	{
		if (index == 0 || dp[index] == true)
		{
			for (int j = 0; j < N; j++)
			{
				int findIndex = str.find(inputs[j], index);
				if (findIndex == index)
				{
					dp[index + inputs[j].length()] = true;
				}
			}
		}
	}
	if (dp[M] == true)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
	return 0;
}