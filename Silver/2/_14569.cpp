#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K, T, M, P, Q;
	int answer = 0;
	cin >> N;
	long long* arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		arr[i] = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> T;
			arr[i] |= (1LL << (T-1));
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		long long m = 0;
		answer = 0;
		cin >> P;
		for (int j = 0; j < P; j++)
		{
			cin >> Q;
			m |= (1LL << (Q-1));
		}
		for (int j = 0; j < N; j++)
		{
			if ((m & arr[j]) == arr[j])
			{
				answer++;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}