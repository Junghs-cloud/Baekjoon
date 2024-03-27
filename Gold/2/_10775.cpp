#include <iostream>
using namespace std;
int* maxGates;

int findParent(int x)
{
	if (maxGates[x] == x)
	{
		return x;
	}
	else
	{
		maxGates[x] = findParent(maxGates[x]);
		return maxGates[x];
	}
}

void merge(int x, int y)
{
	int parentX = findParent(x);
	int parentY = findParent(y);
	maxGates[parentY] = parentX;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int gateNum;
	int dockingAirplanes = 0;
	cin >> N>>M;
	maxGates = new int[N+1];
	for (int i = 0; i < N+1; i++)
	{
		maxGates[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> gateNum;
		int currentMaxGate = findParent(gateNum);
		if (currentMaxGate == 0)
		{
			break;
		}
		else
		{
			merge(currentMaxGate-1, currentMaxGate);
			dockingAirplanes++;
		}
	}
	cout << dockingAirplanes << "\n";
	return 0;
}