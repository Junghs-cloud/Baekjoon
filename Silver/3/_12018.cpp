#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, P, L;
	cin >> N >> M;
	int* pivots = new int[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> L;
		int* arr = new int[P];
		for (int j = 0; j < P; j++)
		{
			cin >> arr[j];
		}
		sort(arr, arr + P, greater());
		if (P < L)
		{
			pivots[i] = 1;
		}
		else
		{
			pivots[i] = arr[L - 1];
		}
	}
	sort(pivots, pivots + N);
	for (int i = 0; i < N; i++)
	{
		if (M >= pivots[i])
		{
			M -= pivots[i];
			answer++;
		}
		else
		{
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}