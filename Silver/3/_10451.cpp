#include <iostream>
using namespace std;
int N;
int* arr;
bool* isVisited;
int answer = 0;

void findCycle(int start)
{
	int nextNode = start;
	while (true)
	{
		isVisited[nextNode] = true;
		int tempNextNode = arr[nextNode];
		if (tempNextNode == start)
		{
			answer++;
			break;
		}
		if (tempNextNode == nextNode)
		{
			break;
		}
		nextNode = tempNextNode;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		answer = 0;
		cin >> N;
		arr = new int[N + 1];
		isVisited = new bool[N + 1];
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			isVisited[i] = false;
		}
		for (int i = 1; i <= N; i++)
		{
			if (isVisited[i] == false)
			{
				findCycle(i);
			}
		}
		cout << answer << "\n";
	}
	return 0;
}