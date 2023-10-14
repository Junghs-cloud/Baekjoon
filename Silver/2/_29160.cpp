#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int position, worth;
	cin >> N >> K;
	priority_queue<int>* arr = new priority_queue<int>[11];
	for (int i = 0; i < N; i++)
	{
		cin >> position >> worth;
		arr[position - 1].push(worth);
	}
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (!arr[j].empty())
			{
				int currentWorth = arr[j].top();
				arr[j].pop();
				if (currentWorth == 0)
				{
					currentWorth = 0;
				}
				else
				{
					currentWorth--;
				}
				arr[j].push(currentWorth);
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < 11; i++)
	{
		if (!arr[i].empty())
		{
			answer += arr[i].top();
		}
	}
	cout << answer << "\n";
	return 0;
}