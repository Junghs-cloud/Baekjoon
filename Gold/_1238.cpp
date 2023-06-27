#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct info
{
	int length;
	int node;
	info(int a, int b)
	{
		length = a;
		node = b;
	}
};

struct cmp
{
	bool operator()(info i1, info i2)
	{
		if (i1.length < i2.length)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int a, b, cost;
	cin >> N >> M >> K;
	priority_queue<info, vector<info>, cmp> pq;
	vector<info>* arr = new vector<info>[N+1];
	int* distance = new int[N + 1];
	int* answers = new int[N + 1];
	int maxDistance = 0;
	for (int i = 0; i < N + 1; i++)
	{
		answers[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> cost;
		arr[a].push_back(info(cost, b));
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			if (i == j)
			{
				distance[j] = 0;
			}
			else
			{
				distance[j] = INF;
			}
		}
		pq.push(info(0, i));
		while (!pq.empty())
		{
			info currentTop = pq.top();
			int currentLength = currentTop.length;
			int currentNode = currentTop.node;
			pq.pop();
			if (distance[currentNode] < currentLength)
			{
				continue;
			}
			for (int j = 0; j < (signed) arr[currentNode].size(); j++)
			{
				int nextNode = arr[currentNode].at(j).node;
				int dist = arr[currentNode].at(j).length;
				if (dist + currentLength < distance[nextNode])
				{
					distance[nextNode] = dist + currentLength;
					pq.push(info(dist + currentLength, nextNode));
				}
			}
		}
		if (i != K)
		{
			answers[i] += distance[K];
		}
		else
		{
			for (int j = 0; j < N + 1; j++)
			{
				answers[j] += distance[j];
			}
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (maxDistance < answers[i])
		{
			maxDistance = answers[i];
		}
	}
	cout << maxDistance << "\n";
	return 0;
}