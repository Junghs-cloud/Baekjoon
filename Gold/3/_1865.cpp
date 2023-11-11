#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N, M, W;
vector<struct info> edges;
int* distanceArr;

struct info
{
	int start;
	int end;
	int dist;
	info(int a, int b, int c)
	{
		start = a;
		end = b;
		dist = c;
	}
};

bool bellmanFord()
{
	distanceArr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int start = edges.at(j).start;
			int nextNode = edges.at(j).end;
			int distanceToNextNode = edges.at(j).dist;
			if (distanceArr[start] == 100000000)
			{
				continue;
			}
			if (distanceArr[start] + distanceToNextNode < distanceArr[nextNode])
			{
				distanceArr[nextNode] = distanceArr[start]+ distanceToNextNode;
				if (i == N)
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		edges.clear();
		int S, E, T;
		cin >> N >> M >> W;
		distanceArr = new int[N + 1];
		bool canReduce = false;
		for (int i = 0; i < N + 1; i++)
		{
			distanceArr[i] = 100000000;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			edges.push_back(info(S, E, T));
			edges.push_back(info(E, S, T));
		}
		for (int i = 1; i < N + 1; i++)
		{
			edges.push_back(info(0, i, 0));
		}
		for (int i = 0; i < W; i++)
		{
			cin >> S >> E >> T;
			edges.push_back(info(S, E, -T));
		}
		if (bellmanFord() == false)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}