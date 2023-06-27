#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> dfsStack;
vector<int>* adjVec;
bool* isVisited;

void dfs(int index)
{
	bool flag = true;
	dfsStack.push(index);
	isVisited[index] = true;
	while (!dfsStack.empty())
	{
		int currentTop = dfsStack.top();
		flag = true;
		for (int i = 0; i < (signed) adjVec[currentTop].size(); i++)
		{
			int num = adjVec[currentTop][i];
			if (isVisited[num] == false)
			{
				isVisited[num] = true;
				flag = false;
				dfsStack.push(num);
				break;
			}
		}
		if (flag == true)
		{
			dfsStack.pop();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	int a, b;
	int num = 0;
	cin >> N >> M;
	adjVec = new vector<int>[N + 1];
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adjVec[a].push_back(b);
		adjVec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (isVisited[i] == false)
		{
			dfs(i);
			num++;
		}
	}
	
	cout << num << "\n";
	return 0;
}