#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int** arr;
bool* isVisited;
vector<int> startTeam;
int* linkTeam;
long long answer;

void backTracking(int depth, int index)
{
	if (depth == N / 2)
	{
		long long startTeamSum = 0;
		long long linkTeamSum = 0;
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				startTeamSum += arr[startTeam[i]][startTeam[j]];
			}
		}
		int index = 0;
		for (int i = 0; i < N; i++)
		{
			if (find(startTeam.begin(), startTeam.end(), i) == startTeam.end())
			{
				linkTeam[index] = i;
				index++;
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				linkTeamSum += arr[linkTeam[i]][linkTeam[j]];
			}
		}
		answer = min(answer, abs(startTeamSum - linkTeamSum));
		return;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				startTeam[depth] = i;
				isVisited[i] = true;
				backTracking(depth + 1, i+1);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int* [N];
	isVisited = new bool[N];
	linkTeam = new int[N / 2];
	answer = 987654321;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = false;
		if (i % 2 == 0)
		{
			startTeam.push_back(0);
		}
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	backTracking(0, 0);
	cout << answer << "\n";
	return 0;
}