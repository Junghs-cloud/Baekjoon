#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> people;
bool* isVisited;
vector<int>* adjacent;
int peopleCount;

void dfs(int want1, int want2)
{
	people.push(want1);
	isVisited[want1] = true;
	while (!people.empty())
	{
		bool flag = false;
		int currentTop = people.top();
		if (currentTop == want2)
		{
			std::cout << peopleCount << "\n";
			return;
		}
		for (int i = 0; i < (signed) adjacent[currentTop].size(); i++)
		{
			int nextVisit = adjacent[currentTop].at(i);
			if (isVisited[nextVisit] == false)
			{
				isVisited[nextVisit] = true;
				people.push(nextVisit);
				flag = true;
				peopleCount++;
				break;
			}
		}
		if (flag == false)
		{
			people.pop();
			peopleCount--;
		}
	}
	std::cout << "-1" << "\n";
}

int main()
{
	int N, M;
	int want1, want2;
	int a, b;
	cin >> N;
	adjacent = new vector<int>[N+1];
	isVisited = new bool[N + 1];
	cin >> want1 >> want2;
	cin >> M;
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	dfs(want1, want2);
	return 0;
}