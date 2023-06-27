#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> dfsStack;
bool* isVisited;
vector<int>* people;
int N, M;
bool ABCDE = false;

void dfs(int person, int length)
{
	if (length == 5)
	{
		ABCDE = true;
		return;
	}
	dfsStack.push(person);
	for (int i = 0; i < (signed) people[person].size(); i++)
	{
		int currentFriend = people[person].at(i);
		if (isVisited[currentFriend] == false)
		{
			isVisited[currentFriend] = true;
			dfs(currentFriend, length + 1);
			isVisited[currentFriend] = false;
		}
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	isVisited = new bool[N];
	people = new vector<int>[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		people[a].push_back(b);
		people[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == false)
		{
			isVisited[i] = true;
			dfs(i, 1);
			if (ABCDE == true)
			{
				break;
			}
			reset();
		}
	}
	if (ABCDE == false)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1" << "\n";
	}
	return 0;
}