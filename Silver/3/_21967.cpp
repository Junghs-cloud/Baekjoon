#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	queue<int>* q = new queue<int>[11];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		q[arr[i]].push(i);
	}
	int left = 0;
	int right = 0;
	int answer = 1;
	int minValue = arr[0];
	int maxValue = arr[0];
	while (left < N)
	{
		while (true)
		{
			right++;
			if (right >= N)
			{
				break;
			}
			minValue = min(minValue, arr[right]);
			maxValue = max(maxValue, arr[right]);
			if (maxValue - minValue > 2)
			{
				break;
			}
			else
			{
				answer = max(answer, right - left + 1);
			}
		}
		right--;
		q[arr[left]].pop();
		minValue = 10;
		maxValue = 1;
		for (int i = 1; i < 11; i++)
		{
			if (!q[i].empty() && q[i].front() <= right)
			{
				minValue = min(minValue, i);
				maxValue = max(maxValue, i);
			}
		}
		left++;
	}
	cout << answer << "\n";
	return 0;
}