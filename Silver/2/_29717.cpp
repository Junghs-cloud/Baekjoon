#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long N;
		cin >> N;
		long long slimeEXP = ((N + 1) * N) / 2;
		long long left = 1;
		long long right = 1000000000;
		long long answer = 1;
		while (left <= right)
		{
			long long level = (left + right) / 2;
			long long needEXP = (level + 1) * level;
			if (needEXP < slimeEXP)
			{
				left = level + 1;
				answer = max(level + 1, answer);
			}
			else if (needEXP > slimeEXP)
			{
				right = level - 1;
			}
			else
			{
				answer = level + 1;
				break;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}