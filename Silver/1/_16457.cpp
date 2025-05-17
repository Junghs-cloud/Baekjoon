#include <iostream>
using namespace std;
int N, M, K;
int answer;
bool* keys;
bool** quests;

void backTracking(int depth, int index)
{
	if (depth == N)
	{
		int questClearCount = 0;
		for (int i = 0; i < M; i++)
		{
			int counts = 0;
			for (int j = 0; j < 2 * N; j++)
			{
				if (quests[i][j] == true && keys[j] == true)
				{
					counts++;
				}
			}
			if (counts == K)
			{
				questClearCount++;
			}
		}
		answer = max(answer, questClearCount);
	}
	else
	{
		for (int i = index; i < 2 * N; i++)
		{
			if (keys[i] == false)
			{
				keys[i] = true;
				backTracking(depth + 1, i + 1);
				keys[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	answer = 0;
	int skillNum;
	cin >> N >> M >> K;
	keys = new bool[2 * N];
	quests = new bool*[M];
	for (int i = 0; i < 2 * N; i++)
	{
		keys[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		quests[i] = new bool[2 * N];
		for (int j = 0; j < 2 * N; j++)
		{
			quests[i][j] = false;
		}
		for (int j = 0; j < K; j++)
		{
			cin >> skillNum;
			quests[i][skillNum - 1] = true;
		}
	}
	backTracking(0, 0);
	cout << answer << "\n";
	return 0;
}