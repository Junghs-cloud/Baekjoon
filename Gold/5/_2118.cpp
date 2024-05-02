#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[2 * N];
	int distanceSum = 0;
	int currentDistance = 0;
	int answer = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		distanceSum += arr[i];
	}
	for (int i = N; i < 2 * N; i++)
	{
		arr[i] = arr[i - N];
	}
	while (start < N)
	{
		while (true)
		{
			currentDistance += arr[end];
			if (currentDistance > distanceSum / 2)
			{
				currentDistance -= arr[end];
				break;
			}
			end++;
		}
		if (currentDistance > answer)
		{
			answer = currentDistance;
		}
		currentDistance -= arr[start];
		start++;
	}
	cout << answer << "\n";
	return 0;
}