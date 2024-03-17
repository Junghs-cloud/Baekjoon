#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int sum = 0;
	int s, e;
	int* arr = new int[1000001];
	int* sums = new int[1000001];
	for (int i = 0; i < 1000001; i++)
	{
		arr[i] = 0;
		sums[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		for (int j = s+1; j <= e; j++)
		{
			arr[j]++;
		}
	}
	sums[0] = 0;
	for (int i = 1; i < 1000001; i++)
	{
		sums[i] = sums[i - 1] + arr[i];
	}
	int start = 0;
	int end = 0;
	int A = 0;
	int B = 0;
	while (end <= 1000000)
	{
		if (start == 0)
		{
			sum = sums[end];
		}
		else
		{
			sum = sums[end] - sums[start];
		}
		if (sum < K)
		{
			end++;
		}
		else if (sum == K)
		{
			A = start;
			B = end;
			break;
		}
		else
		{
			start++;
		}
	}
	std::cout << A <<" " << B << "\n";
	return 0;
}