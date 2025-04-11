#include <iostream>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M;
	if (N == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		int current = 0;
		int answer = 1;
		for (int i = 0; i < N; i++)
		{
			cin >> K;
			current += K;
			if (current > M)
			{
				answer++;
				current = K;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}