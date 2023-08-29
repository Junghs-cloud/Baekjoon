#include <iostream>
#include <vector>
using namespace std;
int* people;
int N, M;

int find(int x)
{
	if (people[x] == x)
	{
		return x;
	}
	else
	{
		return people[x] = find(people[x]);
	}
}

bool hasSameParent(int x, int y)
{
	int xParent = find(x);
	int yParent = find(y);
	if (xParent == yParent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void merge(int x, int y)
{
	int xParent = find(x);
	int yParent = find(y);
	people[xParent] = yParent;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int knowTruth;
	int partyCount;
	int num;
	int firstKnow = -1;
	cin >> N >> M;
	people = new int[N];
	vector<int>* partys = new vector<int>[M];
	bool* canNotTell = new bool[M];
	int answer = M;
	for (int i = 0; i < N; i++)
	{
		people[i] = i;
	}
	cin >> knowTruth;
	for (int i = 0; i < knowTruth; i++)
	{
		cin >> num;
		if (i == 0)
		{
			firstKnow = num;
		}
		else
		{
			merge(num - 1, firstKnow - 1);
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> partyCount;
		canNotTell[i] = false;
		for (int j = 0; j < partyCount; j++)
		{
			cin >> num;
			partys[i].push_back(num);
		}
	}
	if (knowTruth == 0)
	{
		cout << M << "\n";
	}
	else if (knowTruth == N)
	{
		cout << "0" << "\n";
	}
	else
	{
		while (true)
		{
			bool isUpdated = false;
			for (int i = 0; i < M; i++)
			{
				if (canNotTell[i] == false)
				{
					for (int j = 0; j < partys[i].size(); j++)
					{
						if (hasSameParent(partys[i].at(j) - 1, firstKnow - 1) == true)
						{
							canNotTell[i] = true;
							isUpdated = true;
							answer--;
							break;
						}
					}
					if (canNotTell[i] == true)
					{
						for (int j = 0; j < partys[i].size(); j++)
						{
							merge(firstKnow - 1, partys[i].at(j) - 1);
						}
					}
				}

			}
			if (isUpdated == false)
			{
				break;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}