#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	int K;
	int s, e;
	cin >> N >> T;
	int* arr = new int[1001];
	int maxHappiness = 0;
	int maxStart = 0;
	for (int i = 0; i < 1001; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> s >> e;
			for (int k = s; k < e; k++)
			{
				arr[k]++;
			}
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		int current = 0;
		for (int j = i; j <i +  T && j<1001; j++)
		{
			current += arr[j];
		}
		if (current > maxHappiness)
		{
			maxHappiness = current;
			maxStart=i;
		}
	}
	cout << maxStart <<" " << maxStart + T << "\n";
	return 0;
}