#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	cin >> N;
	for (int i = 1; i <= N / 3; i++)
	{
		int left = N - i;
		for (int j = i; j <= left / 2; j++)
		{
			int k = N - i - j;
			if (k >= j && k < i + j)
			{
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}