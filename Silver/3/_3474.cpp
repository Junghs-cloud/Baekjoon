#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long T, N;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long answer = 0;
		cin >> N;
		for (long long i = 5; i <= N; i *= 5)
		{
			answer += N / i;
		}
		cout << answer << "\n";
	}
	return 0;
}