#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool* isVisited;
vector<int>* v;
stack<int> dfsStack;

void reset()
{
	for (int i = 0; i < 26; i++)
	{
		isVisited[i] = false;
	}
	while (!dfsStack.empty())
	{
		dfsStack.pop();
	}
}

bool search(int start, int end)
{
	dfsStack.push(start);
	isVisited[start] = true;
	while (!dfsStack.empty())
	{
		int top = dfsStack.top();
		bool isAdjacent = false;
		if (top == end)
		{
			return true;
		}
		for (int i = 0; i < v[top].size() && isAdjacent==false; i++)
		{
			int next = v[top].at(i);
			if (isVisited[next] == false)
			{
				isAdjacent = true;
				isVisited[next] = true;
				dfsStack.push(next);
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string str;
	cin >> N;
	v = new vector<int>[26];
	isVisited = new bool[26];
	reset();
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		int start = str.at(0) - 97;
		int end = str.at(str.length() - 1) - 97;
		v[start].push_back(end);
	}
	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++)
	{
		getline(cin, str);
		int start = str.at(0) - 97;
		int end = str.at(str.length() - 1) - 97;
		if (search(start, end) == true)
		{
			cout << "T" << "\n";
		}
		else
		{
			cout << "F" << "\n";
		}
		reset();
	}
	return 0;
}