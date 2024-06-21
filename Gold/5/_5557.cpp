#include <iostream>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long** nums = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		nums[i] = new long long[21];
		for (int j = 0; j < 21; j++)
		{
			nums[i][j] = 0;
		}
	}
	nums[0][arr[0]]= 1;
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (j + arr[i] >= 0 && j + arr[i] <= 20)
			{
				nums[i][j + arr[i]] += nums[i - 1][j];
			}
			if (j - arr[i] >= 0 && j - arr[i] <= 20)
			{
				nums[i][j - arr[i]] += nums[i - 1][j];
			}
		}
	}
	for (int i = 0; i < 21; i++)
	{
		nums[N - 1][i] = nums[N - 2][i];
	}
	cout << nums[N - 1][arr[N - 1]] << "\n";
	return 0;
}