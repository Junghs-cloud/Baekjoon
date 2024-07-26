#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long X, Y;
	cin >> X >> Y;
	long long winPercent = (long long)((double)(Y*100) / (double)X);
	long long left = 1;
	long long right = 1000000000;
	long long answer = 1000000001;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long total = X + mid;
		long long win = Y + mid;
		long long newWinPercent = (long long)((double)(win*100) / (double)total);
		if (newWinPercent > winPercent)
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}
	}
	if (answer == 1000000001)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << answer << "\n";
	}
	return 0;
}