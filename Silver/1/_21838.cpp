#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, start, end;
	cin >> N;
	int* arr = new int[N];
	int* mistakes = new int[N+1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	mistakes[0] = 0;
	for (int i = 1; i < N; i++)
	{
		mistakes[i] = mistakes[i - 1];
		if (arr[i-1] > arr[i])
		{
			mistakes[i]++;
		}
	}
	mistakes[N] = mistakes[N - 1];
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		if (end != N && arr[end-1] > arr[end])
		{
			cout << mistakes[end] - mistakes[start - 1] - 1<< "\n";
		}
		else
		{
			cout << mistakes[end] - mistakes[start - 1] << "\n";
		}
	}
	return 0;
}