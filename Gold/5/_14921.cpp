#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int* arr;
int N;
int diff = 200000001;
int answer = 0;

void binarySearch(int num, int start)
{
	int left = start;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (num + arr[mid] == 0)
		{
			diff = 0;
			answer = 0;
			break;
		}
		else if (num + arr[mid] < 0)
		{
			left = mid + 1;
			if (abs(num + arr[mid]) < diff)
			{
				answer = num + arr[mid];
				diff = abs(num + arr[mid]);
			}
		}
		else
		{
			right = mid - 1;
			if (abs(num + arr[mid]) < diff)
			{
				answer = num + arr[mid];
				diff = abs(num + arr[mid]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		binarySearch(arr[i], i + 1);
	}
	cout << answer << "\n";
	return 0;
}