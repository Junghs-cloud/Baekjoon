#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>>* person;
int maxStatus = 0;
int* currentStatus;
bool* isVisited;

void backTracking(int depth)
{
	if (depth == 11)
	{
		int currentMaxStatus = 0;
		for (int i = 0; i < 11; i++)
		{
			currentMaxStatus += currentStatus[i];
		}
		if (maxStatus < currentMaxStatus)
		{
			maxStatus = currentMaxStatus;
		}
		return;
	}
	else
	{
		for (int i = 0; i < (signed) person[depth].size(); i++)
		{
			int index = person[depth].at(i).first;
			if (isVisited[index] == false)
			{
				isVisited[index] = true;
				currentStatus[depth] = person[depth].at(i).second;
				backTracking(depth + 1);
				isVisited[index] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int C;
	int pos;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		maxStatus = 0;
		person = new vector<pair<int, int>>[11];
		currentStatus = new int[11];
		isVisited = new bool[11];
		for (int i = 0; i < 11; i++)
		{
			isVisited[i] = false;
			for (int j = 0; j < 11; j++)
			{
				cin >> pos;
				if (pos > 0)
				{
					person[i].push_back(make_pair(j, pos));
				}
			}
		}
		backTracking(0);
		cout << maxStatus << "\n";
	}
	return 0;
}