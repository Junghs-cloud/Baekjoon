#include <iostream>
#include <stack>
using namespace std;
stack<int> dfsStack;
bool* isVisited;
int* arr;
int canMakeTeamStudent = 0;

int getPoppedCount(int i)
{
	int count = 0;
	while (!dfsStack.empty())
	{
		count++;
		if (dfsStack.top() == i)
		{
			return count;
		}
		dfsStack.pop();
	}
	return 0;
}

void dfs(int i)
{
	isVisited[i] = true;
	dfsStack.push(i);
	while (!dfsStack.empty())
	{
		int top = dfsStack.top();
		int next = arr[top];
		if (isVisited[next] == true && next==i)
		{
			canMakeTeamStudent += dfsStack.size();
			break;
		}
		else if (isVisited[next] == true)
		{
			int poppedCount = getPoppedCount(next);
			canMakeTeamStudent += poppedCount;
			break;
		}
		else
		{
			dfsStack.push(next);
			isVisited[next] = true;
		}
	}
}

void reset()
{
	while (!dfsStack.empty())
	{
		dfsStack.pop();
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
		int N;
		cin >> N;
		arr = new int[N + 1];
		isVisited = new bool[N + 1];
		canMakeTeamStudent = 0;
		for (int i = 1; i < N + 1; i++)
		{
			cin >> arr[i];
			isVisited[i] = false;
		}
		for (int i = 1; i < N + 1; i++)
		{
			if (isVisited[i] == false)
			{
				dfs(i);
				reset();
			}
		}
		cout << N - canMakeTeamStudent << "\n";
	}
	return 0;
}