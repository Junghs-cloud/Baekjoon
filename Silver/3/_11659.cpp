#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int start, end;
	cin >> N >> M;
	long long* accSum = new long long[N + 1];
	accSum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> accSum[i];
		accSum[i] += accSum[i - 1];
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> start >> end;
		cout << accSum[end] - accSum[start - 1]<<"\n";
	}
	return 0;
}