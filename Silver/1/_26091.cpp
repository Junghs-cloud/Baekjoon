#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int answer = 0;
	int* arr = new int[N];
	int start = 0;
	int end = N - 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	while (true)
	{
		if (start >= end)
		{
			break;
		}
		if (arr[start] + arr[end] >= M)
		{
			answer++;
			start++;
			end--;
		}
		else
		{
			start++;
		}
	}
	cout << answer << "\n";
	return 0;
}