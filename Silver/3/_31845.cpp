#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int answer = 0;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater());
	for (int i = 0; i < (N+1) / 2; i++)
	{
		if (i == M)
		{
			break;
		}
		if (arr[i] > 0)
		{
			answer += arr[i];
		}
		else
		{
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}