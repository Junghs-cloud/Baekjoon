#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int* arr = new int[100001];
	int* inputs = new int[N];
	int start = 0;
	int end = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> inputs[i];
	}
	for (int i = 0; i < 100001; i++)
	{
		arr[i] = 0;
	}
	while (true)
	{
		if (end == N)
		{
			break;
		}
		int num = inputs[end];
		arr[num]++;
		while (arr[num] > K && start <= end)
		{
			int startNum = inputs[start];
			arr[startNum]--;
			start++;
		}
		answer = max(answer, end - start + 1);
		end++;
	}
	cout << answer << "\n";
	return 0;
}