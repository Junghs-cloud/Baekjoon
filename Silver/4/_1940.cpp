#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int start = 0;
	int end = N-1;
	int answer = 0;
	while (start < end)
	{
		if (arr[start] + arr[end] == M)
		{
			start++;
			end--;
			answer++;
		}
		else if (arr[start] + arr[end] < M)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout << answer << "\n";
	return 0;
}