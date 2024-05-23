#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	long long num;
	cin >> N>>M;
	long long* sums = new long long[N+1];
	long long answer = 0;
	sums[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		cin >> num;
		sums[i] = sums[i - 1] + num;
	}
	for (int i = M; i < N + 1; i++)
	{
		answer = max(answer, sums[i] - sums[i - M]);
	}
	cout << answer << "\n";
	return 0;
}