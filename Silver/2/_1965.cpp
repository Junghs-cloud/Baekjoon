#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	cin >> N;
	int* arr = new int[N];
	int* maxDepth = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		maxDepth[i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && maxDepth[j] + 1 > maxDepth[i])
			{
				maxDepth[i] = maxDepth[j] + 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		if (maxDepth[i] > answer)
		{
			answer = maxDepth[i];
		}
	}
	cout << answer << "\n";
	return 0;
}