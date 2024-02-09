#include <iostream>
#include <vector>
#include <algorithm>
#define INF 200000000
using namespace std;
int N, M, K;
int** arr;
int* friends;
vector<int> minCities;
int minCost = 987654321;

void floydWarshall()
{
	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

void getMinCity()
{
	for (int i = 1; i < N + 1; i++)
	{
		int maxCost = 0;
		for (int j = 0; j < K; j++)
		{
			maxCost = max(maxCost, arr[i][friends[j]] + arr[friends[j]][i]);
		}
		if (maxCost < minCost)
		{
			minCost = maxCost;
			minCities.clear();
			minCities.push_back(i);
		}
		else if (maxCost == minCost)
		{
			minCities.push_back(i);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int start, end, cost;
	cin >> N>>M;
	arr = new int*[N+1];
	for (int i = 0; i < N+1; i++)
	{
		arr[i] = new int[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;
		arr[start][end] = cost;
	}
	cin >> K;
	friends = new int[K];
	for (int i = 0; i < K; i++)
	{
		cin >> friends[i];
	}
	floydWarshall();
	getMinCity();
	for (int i = 0; i < minCities.size(); i++)
	{
		cout << minCities.at(i) << " ";
	}
	return 0;
}