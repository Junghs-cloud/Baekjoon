#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, M;
	cin >> N >> M;
	if (N >= M)
	{
		cout << 0 << "\n";
	}
	else
	{
		long long answer = 1;
		for (long long i = 1; i <= N; i++)
		{
			answer = (answer  % M) * (i % M);
			answer %= M;
		}
		cout << answer << "\n";
	}
	return 0;
}