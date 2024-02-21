#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int maxIndex = -1;
	int maxLevel = -1;
	long long answer = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > maxLevel)
		{
			maxLevel = arr[i];
			maxIndex = i;
		}
	}
	for (int i = 0; i < maxIndex; i++)
	{
		answer += maxLevel + arr[i];
	}
	for (int i = maxIndex+1; i < N; i++)
	{
		answer += maxLevel + arr[i];
	}
	cout << answer << "\n";
	return 0;
}