#include <iostream>
#include <vector>
#include <utility>
#define INF 123456789
using namespace std;
int V, E;
int** lengths;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> V >> E;
	lengths = new int* [V + 1];
	int answer = INF;
	for (int i = 0; i < V + 1; i++)
	{
		lengths[i] = new int[V + 1];
		for (int j = 0; j < V + 1; j++)
		{
			lengths[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		lengths[a][b] = c;
	}
	for (int j = 0; j < V + 1; j++)
	{
		for (int i = 0; i < V + 1; i++)
		{
			for (int k = 0; k < V + 1; k++)
			{
				if (lengths[i][j] > lengths[i][k] + lengths[k][j])
				{
					lengths[i][j] = lengths[i][k] + lengths[k][j];
				}
			}
		}
	}
	for (int i = 1; i < V + 1; i++)
	{
		answer = min(answer, lengths[i][i]);
	}
	if (answer == INF)
	{
		answer = -1;
	}
	cout << answer << "\n";
	return 0;
}