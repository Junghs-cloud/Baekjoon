#include <iostream>
using namespace std;

int N, K;
int* exercises;
bool* isVisited;
int caseCount = 0;
int weight = 500;

bool isPromising(int index)
{
	if (weight + exercises[index] - K >=500)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dfs(int depth)
{
	if (depth == N)
	{
		caseCount++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				if (isPromising(i))
				{
					weight += exercises[i] - K;
					dfs(depth + 1);
					weight -= exercises[i] - K;
				}
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	exercises = new int[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> exercises[i];
		isVisited[i] = false;
	}
	dfs(0);
	cout << caseCount << "\n";
	return 0;
}