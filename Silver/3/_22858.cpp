#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* P = new int[N];
	int* D = new int[N];
	int* temp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> D[i];
		temp[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index = D[j] - 1;
			temp[index] = P[j];
		}
		for (int j = 0; j < N; j++)
		{
			P[j] = temp[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << temp[i] << " ";
	}
	return 0;
}