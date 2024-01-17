#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long* length = new long long[N];
	long long* oils = new long long[N];
	for (int i = 0; i < N-1; i++)
	{
		cin >> length[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> oils[i];
	}
	long long cost = 0;
	long long cmp = oils[0];
	long long currentLength = length[0];
	for (int i = 1; i < N-1; i++)
	{
		if (cmp <= oils[i])
		{
			currentLength += length[i];
		}
		else
		{
			cost += cmp * currentLength;
			cmp = oils[i];
			currentLength = length[i];
		}
	}
	cost += cmp * currentLength;
	cout << cost << "\n";
	return 0;
}