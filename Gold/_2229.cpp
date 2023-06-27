#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* line = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	line[0] = 0;
	if (N >= 2)
	{
		line[1] = abs(arr[0] - arr[1]);
	}
	for (int i = 2; i < N; i++)
	{
		int currentMax = 0;
		for (int j = 0; j < i; j++)
		{
			int max = -1;
			int min = 10001;
			
			for (int k = j + 1; k <= i; k++)
			{
				if (arr[k] > max)
				{
					max = arr[k];
				}
				if (arr[k] < min)
				{
					min = arr[k];
				}
			}
			if (line[j] + (max - min) > currentMax)
			{
				currentMax = line[j] + (max - min);
			}
		}
		line[i] = currentMax;
	}
	cout << line[N - 1] << "\n";
	return 0;
}