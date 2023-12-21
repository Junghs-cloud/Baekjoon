#include <iostream>
using namespace std;
int* arr;
int N, M;
int answer = 100000;

void binarySearch(int left, int right)
{

	while (left <= right)
	{
		int mid = (left + right) / 2;
		bool b = true;
		if (arr[0] - mid > 0)
		{
			b = false;
		}
		for (int i = 1; i < M; i++)
		{
			if (arr[i] - mid > arr[i - 1] + mid)
			{
				b = false;
			}
		}
		if (arr[M - 1] + mid < N)
		{
			b = false;
		}
		if ( b == false)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			answer = mid;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>M;
	arr = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	binarySearch(1, 100001);
	cout << answer << "\n";
	return 0;
}