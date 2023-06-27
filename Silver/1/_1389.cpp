#include <iostream>
#include <cmath>
using namespace std;
int N, M;
int** arr;

void floydWarshall()
{
	for (int person = 1; person <= N; person++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int otherPerson = 1; otherPerson <= N; otherPerson++)
			{
				if (j != otherPerson)
				{
					arr[j][otherPerson] = min(arr[j][person] + arr[person][otherPerson], arr[j][otherPerson]);
				}
			}
		}
	}
}

int findMinPerson()
{
	int minKevinBaconNum = 99999999;
	int minPerson = 1;
	for (int i = 1; i <= N; i++)
	{
		int kevinBaconNum = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
			{
				kevinBaconNum += arr[i][j];
			}
		}
		if (kevinBaconNum < minKevinBaconNum)
		{
			minKevinBaconNum = kevinBaconNum;
			minPerson = i;
		}
	}
	return minPerson;
}

int main()
{
	int a, b;
	cin >> N >> M;
	arr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			arr[i][j] = 999;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	floydWarshall();
	int minPerson = findMinPerson();
	cout << minPerson << "\n";
	return 0;
}