#include <iostream>
#include <algorithm>
using namespace std;

int checkCount(int* arr, int size, int coolTime)
{
	int nextTime = 0;
	int answer = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= nextTime)
		{
			answer++;
			nextTime = arr[i] + coolTime;
		}
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* arr1 = new int[N];
	int* arr2 = new int[M];
	for (int i = 0; i < N; i++)
	{
		cin >> arr1[i];
	}
	sort(arr1, arr1 + N);
	for (int j = 0; j < M; j++)
	{
		cin >> arr2[j];
	}
	sort(arr2, arr2 + M);
	cout << checkCount(arr1, N, 100) << " " << checkCount(arr2, M, 360) << "\n";
	return 0;
}